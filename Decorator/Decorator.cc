#include <iostream>

using namespace std;

class DataSource
{
public:
    virtual void writeData(string data) = 0;
    virtual string readData() = 0;
};

class TextDataSource : public DataSource
{
private:
    string data;
public:
    void writeData(string data)
    {
        this->data = data;
    }
    string readData()
    {
        return data;
    }
};

class PrefixDecorator : public DataSource
{
private:
    DataSource *wrappee;
    string prefix;
public:
    PrefixDecorator(DataSource *wrappee, string prefix)
    {
        this->wrappee = wrappee;
        this->prefix = prefix;
    }
    void writeData(string data)
    {
        wrappee->writeData(prefix + data);
    }
    string readData()
    {
        return prefix + wrappee->readData();
    }
};

class PostfixDecorator : public DataSource
{
private:
    DataSource *wrappee;
    string postfix;
public:
    PostfixDecorator(DataSource *wrappee, string postfix)
    {
        this->wrappee = wrappee;
        this->postfix = postfix;
    }
    void writeData(string data)
    {
        wrappee->writeData(data + postfix);
    }
    string readData()
    {
        return wrappee->readData() + postfix;
    }
};

int main() {
    DataSource *source = new TextDataSource();
    source->writeData("world");
    source = new PrefixDecorator(source, "hello ");
    source = new PostfixDecorator(source, "!");
    cout << "data=" << source->readData() << endl;
    return 0;
}
#include <iostream>

using namespace std;

class IDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class Radio : public IDevice
{
public:
    void turnOn()
    {
        cout << "Radio is on" << endl;
    }
    void turnOff()
    {
        cout << "Radio is off" << endl;
    }
};

class TV : public IDevice
{
public:
    void turnOn()
    {
        cout << "TV is on" << endl;
    }
    void turnOff()
    {
        cout << "TV is off" << endl;
    }
};

class Remote
{
private:
    IDevice *device;
public:
    Remote(IDevice *device)
    {
        this->device = device;
    }
    void turnOn()
    {
        device->turnOn();
    }
    void turnOff()
    {
        device->turnOff();
    }
};

int main()
{
    IDevice *radio = new Radio();
    IDevice *tv = new TV();
    Remote *remote1 = new Remote(radio);
    remote1->turnOn();
    remote1->turnOff();
    Remote *remote2 = new Remote(tv);
    remote2->turnOn();
    remote2->turnOff();
    return 0;
}
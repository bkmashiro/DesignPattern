#include <iostream>
#include <string>

using namespace std;

class ButtonInterface
{
public:
    virtual void render() = 0;
    virtual void onClick() = 0;
};

class WindowsButton : public ButtonInterface
{
public:
    void render()
    {
        cout << "WindowsButton" << endl;
    }
    void onClick()
    {
        cout << "WindowsButton onClick" << endl;
    }
};

class MacButton : public ButtonInterface
{
public:
    void render()
    {
        cout << "MacButton" << endl;
    }
    void onClick()
    {
        cout << "MacButton onClick" << endl;
    }
};

class CheckboxInterface
{
public:
    virtual void render() = 0;
    virtual void onClick() = 0;
};

class WindowsCheckbox : public CheckboxInterface
{
public:
    void render()
    {
        cout << "WindowsCheckbox" << endl;
    }
    void onClick()
    {
        cout << "WindowsCheckbox onClick" << endl;
    }
};

class MacCheckbox : public CheckboxInterface
{
public:
    void render()
    {
        cout << "MacCheckbox" << endl;
    }
    void onClick()
    {
        cout << "MacCheckbox onClick" << endl;
    }
};

class GUIFactoryInterface
{
public:
    virtual ButtonInterface *createButton() = 0;
    virtual CheckboxInterface *createCheckbox() = 0;
};

class WindowsFactory : public GUIFactoryInterface
{
public:
    ButtonInterface *createButton()
    {
        return new WindowsButton();
    }
    CheckboxInterface *createCheckbox()
    {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactoryInterface
{
public:
    ButtonInterface *createButton()
    {
        return new MacButton();
    }
    CheckboxInterface *createCheckbox()
    {
        return new MacCheckbox();
    }
};

class Application
{
private:
    GUIFactoryInterface *factory;

public:
    Application(GUIFactoryInterface *factory)
    {
        this->factory = factory;
    }
    void createUI()
    {
        ButtonInterface *button = factory->createButton();
        button->render();
        CheckboxInterface *checkbox = factory->createCheckbox();
        checkbox->render();
    }
};

int main()
{
    string os;
    cout << "Please input OS type (Windows/other)" << endl;
    cin >> os;

    GUIFactoryInterface *factory;
    if (os == "Windows")
    {
        factory = new WindowsFactory();
    }
    else
    {
        factory = new MacFactory();
    }

    Application *app = new Application(factory);
    app->createUI();

    return 0;
}
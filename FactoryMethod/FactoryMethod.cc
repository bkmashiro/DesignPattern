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

class HTMLButton : public ButtonInterface
{
public:
    void render()
    {
        cout << "HTMLButton" << endl;
    }
    void onClick()
    {
        cout << "HTMLButton onClick" << endl;
    }
};

class DialogueInterface
{
public:
    virtual ButtonInterface *createButton() = 0;
    virtual void render() = 0;
};

class WindowsDialog : public DialogueInterface
{
public:
    ButtonInterface *createButton()
    {
        return new WindowsButton();
    }
    void render()
    {
        ButtonInterface *button = createButton();
        button->render();
    }
};

class HTMLDialog : public DialogueInterface
{
public:
    ButtonInterface *createButton()
    {
        return new HTMLButton();
    }
    void render()
    {
        ButtonInterface *button = createButton();
        button->render();
    }
};

int main()
{
    string os;
    cout << "Please input OS type (Windows/other)" << endl;
    cin >> os;

    DialogueInterface *dialog;
    if (os == "Windows")
    {
        dialog = new WindowsDialog();
    }
    else
    {
        dialog = new HTMLDialog();
    }
    dialog->render();
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class IGraphic {
public:
    virtual void Draw() = 0;
};

class CompositeGraphic : public IGraphic {
public:
    void Draw() override {
        for (auto& graphic : m_graphics) {
            graphic->Draw();
        }
    }

    CompositeGraphic* Add(IGraphic* graphic) {
        m_graphics.push_back(graphic);
        return this;
    }

    CompositeGraphic* Remove(IGraphic* graphic) {
        m_graphics.erase(remove(m_graphics.begin(), m_graphics.end(), graphic), m_graphics.end());
        return this;
    }

private:
    vector<IGraphic*> m_graphics;
};

class Ellipse : public IGraphic {
public:
    void Draw() override {
        cout << "Ellipse" << endl;
    }
};

class Circle : public IGraphic {
public:
    void Draw() override {
        cout << "Circle" << endl;
    }
};

class Rectangle : public IGraphic {
public:
    void Draw() override {
        cout << "Rectangle" << endl;
    }
};

class Picture : public IGraphic {
public:
    void Draw() override {
        cout << "Picture" << endl;
    }
};

int main() {
    Ellipse* ellipse1 = new Ellipse();
    Ellipse* ellipse2 = new Ellipse();
    Circle* circle1 = new Circle();
    Rectangle* rectangle1 = new Rectangle();
    Picture* picture1 = new Picture();

    CompositeGraphic* graphic = new CompositeGraphic();
    CompositeGraphic* graphic1 = new CompositeGraphic();
    CompositeGraphic* graphic2 = new CompositeGraphic();

    graphic1
        ->Add(ellipse1)
        ->Add(ellipse2)
        ->Add(circle1);

    graphic2
        ->Add(rectangle1)
        ->Add(picture1);

    graphic
        ->Add(graphic1)
        ->Add(graphic2);

    graphic->Draw();

    return 0;
}
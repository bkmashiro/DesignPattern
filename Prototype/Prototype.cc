#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape
{
private: 
    int x;
    int y;
    string color;

public:
    Shape(int x, int y, string color)
    {
        this->x = x;
        this->y = y;
        this->color = color;
    }
    Shape(const Shape &shape)
    {
        this->x = shape.x;
        this->y = shape.y;
        this->color = shape.color;
    }
    virtual Shape *clone() = 0;
    string toString()
    {
        return "x: " + to_string(x) + ", y: " + to_string(y) + ", color: " + color;
    }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;
public:
    Rectangle(int x, int y, string color, int width, int height) : Shape(x, y, color)
    {
        this->width = width;
        this->height = height;
    }
    Rectangle(const Rectangle &rectangle) : Shape(rectangle)
    {
        this->width = rectangle.width;
        this->height = rectangle.height;
    }
    Shape *clone()
    {
        return new Rectangle(*this);
    }
    string toString()
    {
        return Shape::toString() + ", width: " + to_string(width) + ", height: " + to_string(height);
    }
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int x, int y, string color, int radius) : Shape(x, y, color)
    {
        this->radius = radius;
    }
    Circle(const Circle &circle) : Shape(circle)
    {
        this->radius = circle.radius;
    }
    Shape *clone()
    {
        return new Circle(*this);
    }
    string toString()
    {
        return Shape::toString() + ", radius: " + to_string(radius);
    }
};


int main() {
    vector<Shape *> shapes;
    shapes.push_back(new Rectangle(1, 2, "red", 3, 4));
    shapes.push_back(new Circle(5, 6, "blue", 7));
    vector<Shape *> shapesCopy;
    for (int i = 0; i < shapes.size(); i++)
    {
        shapesCopy.push_back(shapes[i]->clone());
    }
    // print shapesCopy
    for (int i = 0; i < shapesCopy.size(); i++)
    {
        cout << shapesCopy[i]->toString() << endl;
    }
    return 0;
}
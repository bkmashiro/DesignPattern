#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Treetype {
public:
    string name;
    string color;
    string texture;

    Treetype(string name, string color, string texture)
    {
        this->name = name;
        this->color = color;
        this->texture = texture;
    }

    void draw(int x, int y)
    {
        cout << "Drawing tree at " << x << ", " << y << endl;
    }
};

class Tree {
public:
    int x;
    int y;
    Treetype *type; 
    
    Tree(int x, int y, Treetype *type)
    {
        this->x = x;
        this->y = y;
        this->type = type;
    }

    void draw()
    {
        type->draw(x, y);
    }
};

class TreeFactory {
private:
    vector<Tree> trees;

    TreeFactory()
    {
    }

public:
    static TreeFactory *getInstance()
    {
        static TreeFactory instance;
        return &instance;
    }

    Tree *getTree(int x, int y, string name, string color, string texture)
    {
        for (int i = 0; i < trees.size(); i++)
        {
            if (trees[i].x == x && trees[i].y == y)
            {
                return &trees[i];
            }
        }
        Treetype *type = new Treetype(name, color, texture);
        Tree *tree = new Tree(x, y, type);
        trees.push_back(*tree);
        return tree;
    }

    void drawAll()
    {
        for (int i = 0; i < trees.size(); i++)
        {
            trees[i].draw();
        }
    }
};

int main()
{
    TreeFactory *factory = TreeFactory::getInstance();
    Tree *tree1 = factory->getTree(1, 2, "Oak", "Green", "Rough");
    Tree *tree2 = factory->getTree(3, 4, "Oak", "Green", "Rough");
    Tree *tree3 = factory->getTree(5, 6, "Oak", "Green", "Rough");
    Tree *tree4 = factory->getTree(1, 2, "Oak", "Green", "Rough");
    Tree *tree5 = factory->getTree(3, 4, "Oak", "Green", "Rough");
    Tree *tree6 = factory->getTree(5, 6, "Oak", "Green", "Rough");
    Tree *tree7 = factory->getTree(1, 2, "Oak", "Green", "Rough");
    Tree *tree8 = factory->getTree(3, 4, "Oak", "Green", "Rough");
    Tree *tree9 = factory->getTree(5, 6, "Oak", "Green", "Rough");
    Tree *tree10 = factory->getTree(1, 2, "Oak", "Green", "Rough");
    Tree *tree11 = factory->getTree(3, 4, "Oak", "Green", "Rough");
    Tree *tree12 = factory->getTree(5, 6, "Oak", "Green", "Rough");
    Tree *tree13 = factory->getTree(1, 2, "Oak", "Green", "Rough");
    Tree *tree14 = factory->getTree(3, 4, "Oak", "Green", "Rough");
    Tree *tree15 = factory->getTree(5, 6, "Oak", "Green", "Rough");
    Tree *tree16 = factory->getTree(1, 2, "Oak", "Green", "Rough");
    Tree *tree17 = factory->getTree(3, 4, "Oak", "Green", "Rough");
    Tree *tree18 = factory->getTree(5, 6, "Oak", "Green", "Rough");

    // draw all
    factory->drawAll();
    return 0;
}
#include <iostream>

using namespace std;

class IShape {
    public:
    void virtual display(int x1, int y1,
                 int x2, int y2) = 0;
};

class LegacyRectangle {
    public:
    void oldDisplay(int x1, int y1,
                    int h,  int w) {
        cout << "LegacyRectangle: " << x1 << ", " << y1 << ", " << h << ", " << w << endl;
    }
};

// class Rectangle: public IShape {
//     public:
//     void display(int x1, int y1,
//                  int x2, int y2) {
//         LegacyRectangle* legacyRectangle = new LegacyRectangle();
//         legacyRectangle->oldDisplay(x1, y1, x2 - x1, y2 - y1);
//     }        
// };

class Rectangle: public IShape, private LegacyRectangle {
    public:
    void display(int x1, int y1,
                 int x2, int y2) {
        LegacyRectangle* legacyRectangle = new LegacyRectangle();
        legacyRectangle->oldDisplay(x1, y1, x2 - x1, y2 - y1);
    }        
};



int main() {
    IShape* shape = new Rectangle();
    shape->display(1, 2, 3, 4);
    return 0;
}
#include <iostream>

using namespace std;

class DiskImage {
private:
    string path;
public:
    DiskImage(string path) {
        this->path = path;
    }
    void draw() {
        cout << "DiskImage::draw()" << endl;
    }
};

class CachedImage {
private:
    DiskImage *diskImage = nullptr;
    string path;
public:
    CachedImage(string path) {
        this->path = path;
    }
    void draw() {
        if (this->diskImage == nullptr) {
            cout << "lazy initilized Diskimage" << endl;
            this->diskImage = new DiskImage(this->path);
        } else cout << "Cache hit!" << endl;
        this->diskImage->draw();
    }
};

int main() {
    CachedImage *image = new CachedImage("proxy.cc");
    image->draw();
    image->draw();
    image->draw();
    return 0;
}

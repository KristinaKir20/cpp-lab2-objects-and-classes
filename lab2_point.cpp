#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int  getX()      { return x; }
    int  getY()      { return y; }

    void print() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    cout << "=== Статический объект ===" << endl;
    Point p1;                 // создаётся на стеке
    p1.setX(1);
    p1.setY(2);
    p1.print();

    cout << "=== Динамический объект ===" << endl;
    Point *p2 = new Point();  // создаётся в куче
    p2->setX(3);
    p2->setY(4);
    p2->print();
    delete p2;              
  
    return 0;
}
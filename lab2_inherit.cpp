#include <iostream>
using namespace std;

class Point {
protected:                  // наследнику доступно, снаружи — нет
    int x;
    int y;
public:
    Point() : x(0), y(0) {
        cout << "Point(): конструктор" << endl;
    }
    Point(int x, int y) : x(x), y(y) {
        cout << "Point(int,int): конструктор" << endl;
    }
    Point(const Point &o) : x(o.x), y(o.y) {
        cout << "Point(const Point&): конструктор копирования" << endl;
    }
    ~Point() {
        cout << "~Point(): деструктор" << endl;
    }

    void print() { cout << "Point(" << x << "," << y << ")" << endl; }
};

class Circle : public Point {
private:
    int r;
public:
    Circle() : Point(), r(1) {
        cout << "Circle(): конструктор" << endl;
    }
    Circle(int x, int y, int r) : Point(x, y), r(r) {
        cout << "Circle(int,int,int): конструктор" << endl;
    }
    ~Circle() {
        cout << "~Circle(): деструктор" << endl;
    }

    void printCircle() {
        cout << "Circle: центр (" << x << "," << y << "), R=" << r << endl;
    }
};

int main() {
    cout << "=== Создание Circle ===" << endl;
    Circle c(10, 20, 5);
    c.printCircle();
    c.print();          // унаследованный метод
    // c.x = 1;         // ошибка: x — protected, снаружи main недоступно
    cout << "=== Конец main ===" << endl;
    return 0;
}
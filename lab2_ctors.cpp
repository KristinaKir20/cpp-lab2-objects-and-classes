#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    // конструктор без параметров
    Point() : x(0), y(0) {
        cout << "Point(): конструктор без параметров" << endl;
    }

    // конструктор с параметрами (инициализация в списке)
    Point(int x, int y) : x(x), y(y) {
        cout << "Point(int,int): конструктор с параметрами" << endl;
    }

    // конструктор копирования
    Point(const Point &other) : x(other.x), y(other.y) {
        cout << "Point(const Point&): конструктор копирования" << endl;
    }

    // деструктор
    ~Point() {
        cout << "~Point(): деструктор (" << x << "," << y << ")" << endl;
    }

    void print() { cout << "Point(" << x << "," << y << ")" << endl; }
};

int main() {
    cout << "--- без параметров ---" << endl;
    Point a;          // вызов Point()

    cout << "--- с параметрами ---" << endl;
    Point b(5, 6);    // вызов Point(int,int)

    cout << "--- копирование ---" << endl;
    Point c(b);       // вызов Point(const Point&)

    cout << "--- динамический ---" << endl;
    Point *d = new Point(7, 8);
    d->print();
    delete d;         // явно вызывается деструктор

    cout << "--- конец main: сейчас пойдут деструкторы a, b, c ---" << endl;
    return 0;
}
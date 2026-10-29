#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void setX(int v) { x = v; }
    int  getX() { return x; }
    void print() { cout << "Point(" << x << "," << y << ")" << endl; }
};

class Circle : public Point {
private:
    int r;
public:
    Circle(int x, int y, int r) : Point(x, y), r(r) {}
    void printCircle() { cout << "Circle R=" << r << endl; }
};

int main() {
    cout << "=== 1. Копирование объекта ===" << endl;
    Point a(1, 1);
    Point b = a;             // копирование (вызовется конструктор копирования)
    b.setX(100);
    a.print();               // (1,1) — не изменился
    b.print();               // (100,1) — у b своя копия

    cout << "=== 2. Копирование указателя ===" << endl;
    Point *p1 = new Point(5, 5);
    Point *p2 = p1;          // копируется АДРЕС, не объект
    p2->setX(999);
    p1->print();             // (999,5) — это тот же объект!
    p2->print();             // (999,5)
    delete p1;               // p2 теперь «висит» — обращаться нельзя

    cout << "=== 3. Указатель на базу → объект-потомок ===" << endl;
    Point *base = new Circle(2, 3, 10);
    base->print();           // можно вызвать только методы Point
    // base->printCircle();  // ОШИБКА: у Point нет такого метода
    delete base;             // вызовется только ~Point!

    // А вот так — нормально, вызываем оба метода:
    Circle *c = new Circle(4, 4, 7);
    c->print();
    c->printCircle();
    delete c;

    return 0;
}
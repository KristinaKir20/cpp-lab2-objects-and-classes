#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) { cout << "Shape(" << n << "): конструктор" << endl; }
    ~Shape() { cout << "~Shape(): деструктор" << endl; }

    void describe() {
        cout << "Это фигура: " << name << endl;
    }
};

class Square : public Shape {
private:
    int side;
public:
    Square(int s) : Shape("квадрат"), side(s) {
        cout << "Square(" << s << "): конструктор" << endl;
    }
    ~Square() { cout << "~Square(): деструктор" << endl; }

    // переопределяем метод предка (без virtual!)
    void describe() {
        Shape::describe();    // вызываем унаследованный вариант
        cout << "  сторона = " << side << endl;
    }
};

int main() {
    Square sq(4);
    sq.describe();     // вызовется Square::describe

    // интересный момент: через указатель на базовый класс
    Shape *sp = new Square(7);
    sp->describe();    // вызовется Shape::describe, т.к. метод НЕ виртуальный!
    delete sp;         // вызовется ТОЛЬКО ~Shape (тоже не виртуальный)
    return 0;
}
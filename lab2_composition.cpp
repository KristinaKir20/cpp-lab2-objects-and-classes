#include <iostream>
using namespace std;

// --- Отдельный класс «двигатель» ---
class Engine {
public:
    Engine()  { cout << "Engine(): создан" << endl; }
    ~Engine() { cout << "~Engine(): удалён" << endl; }
    void work() { cout << "  двигатель работает" << endl; }
};

// --- Вариант A: храним объект прямо ---
class CarWithObject {
private:
    Engine engine;      // объект-атрибут (не указатель!)
    string name;
public:
    CarWithObject(string n) : engine(), name(n) {
        cout << "CarWithObject(" << n << "): конструктор" << endl;
    }
    ~CarWithObject() {
        cout << "~CarWithObject(" << name << "): деструктор" << endl;
        // engine удалится автоматически после этого
    }
    void go() { engine.work(); }
};

// --- Вариант B: храним указатель ---
class CarWithPointer {
private:
    Engine *engine;     // указатель на объект
    string name;
public:
    CarWithPointer(string n) : engine(new Engine()), name(n) {
        cout << "CarWithPointer(" << n << "): конструктор" << endl;
    }
    ~CarWithPointer() {
        cout << "~CarWithPointer(" << name << "): деструктор" << endl;
        delete engine;  // надо удалять вручную!
    }
    void go() { engine->work(); }
};

int main() {
    cout << "=== CarWithObject ===" << endl;
    CarWithObject a("A");
    a.go();

    cout << "=== CarWithPointer ===" << endl;
    CarWithPointer b("B");
    b.go();

    cout << "=== Конец main ===" << endl;
    return 0;
}
#include <iostream>
#include "Bus.h"
#include <windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // 1. Статичний об'єкт
    cout << "=== 1. Звичайний об'єкт Bus ===" << endl;
    Car c1;
    c1.Init("MAN", 6, 320.0);
    Bus b1;
    b1.Init(c1, 45);
    b1.Display();

    cout << "\nЗміна марки та кількості місць для b1:" << endl;
    b1.changeBrand("Neoplan");
    b1.changeSeats(50);
    b1.Display();

    // 2. Введення з клавіатури через метод Read()
    cout << "\n=== 2. Введення об'єкта Bus (метод Read) ===" << endl;
    Bus b2;
    b2.Read();
    cout << "\nРезультат виведення (метод Display):" << endl;
    b2.Display();

    // 3. Динамічний об'єкт
    cout << "\n=== 3. Динамічний об'єкт Bus ===" << endl;
    Bus* b3 = new Bus();
    Car c3;
    c3.Init("Ikarus", 8, 280.0);
    b3->Init(c3, 30);
    cout << "toString(): " << b3->toString() << endl;
    delete b3;

    // 4. Масив об'єктів
    cout << "\n=== 4. Масив об'єктів Bus ===" << endl;
    Bus buses[2];
    Car c4_1, c4_2;
    c4_1.Init("Mercedes-Benz", 6, 360.0);
    c4_2.Init("Volvo", 6, 380.0);

    buses[0].Init(c4_1, 52);
    buses[1].Init(c4_2, 48);

    for (int i = 0; i < 2; ++i) {
        cout << "Автобус №" << i + 1 << ": ";
        buses[i].Display();
    }

    return 0;
}
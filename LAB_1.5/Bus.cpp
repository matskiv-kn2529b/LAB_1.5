#include "Bus.h"
#include <windows.h>
#include <iostream>
#include <sstream>

bool Bus::setCar(const Car& car) {
    this->car = car;
    return true;
}

bool Bus::setSeats(int seats) {
    if (seats > 0) {
        this->seats = seats;
        return true;
    }
    return false;
}

void Bus::changeBrand(const std::string& newBrand) {
    if (!car.setBrand(newBrand)) {
        std::cout << "Помилка перевизначення марки!" << std::endl;
    }
}

void Bus::changeSeats(int seats) {
    if (!setSeats(seats)) {
        std::cout << "Помилка: кількість пасажирських місць має бути більшою за 0!" << std::endl;
    }
}

bool Bus::Init(const Car& car, int seats) {
    return setCar(car) && setSeats(seats);
}

void Bus::Read() {
    Car c;
    int s;

    std::cout << "\n--- Введення даних для автомашини автобуса ---" << std::endl;
    c.Read();

    do {
        std::cout << "Введіть кількість пасажирських місць (> 0): ";
        std::cin >> s;
    } while (!setSeats(s));

    setCar(c);
}

void Bus::Display() const {
    std::cout << toString() << std::endl;
}

std::string Bus::toString() const {
    std::ostringstream sout;
    sout << "Автобус [" << car.toString() << ", Пасажирських місць: " << seats << "]";
    return sout.str();
}
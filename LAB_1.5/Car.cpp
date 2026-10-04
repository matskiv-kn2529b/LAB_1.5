#include "Car.h"
#include <iostream>
#include <sstream>
#include <windows.h>

bool Car::setBrand(const std::string& brand) {
    if (!brand.empty()) {
        this->brand = brand;
        return true;
    }
    return false;
}

bool Car::setCylinders(int cylinders) {
    if (cylinders > 0) {
        this->cylinders = cylinders;
        return true;
    }
    return false;
}

bool Car::setPower(double power) {
    if (power > 0) {
        this->power = power;
        return true;
    }
    return false;
}

void Car::changePower(double delta) {
    if (this->power + delta > 0) {
        this->power += delta;
    }
    else {
        std::cout << "Помилка: потужність повинна залишатися більшою за 0!" << std::endl;
    }
}

bool Car::Init(const std::string& brand, int cylinders, double power) {
    return setBrand(brand) && setCylinders(cylinders) && setPower(power);
}

void Car::Read() {
    std::string brand;
    int cylinders;
    double power;

    do {
        std::cout << "Введіть марку машини: ";
        std::cin >> brand;
        std::cout << "Введіть кількість циліндрів (> 0): ";
        std::cin >> cylinders;
        std::cout << "Введіть потужність (> 0): ";
        std::cin >> power;
    } while (!Init(brand, cylinders, power));
}

void Car::Display() const {
    std::cout << toString() << std::endl;
}

std::string Car::toString() const {
    std::ostringstream sout;
    sout << "Марка: " << brand << ", Циліндрів: " << cylinders << ", Потужність: " << power << " к.с.";
    return sout.str();
}
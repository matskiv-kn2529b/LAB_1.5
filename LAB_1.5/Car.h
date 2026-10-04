#pragma once
#include <string>
#include <windows.h>

class Car {
private:
    std::string brand;
    int cylinders;
    double power;

public:
    std::string getBrand() const { return brand; }
    int getCylinders() const { return cylinders; }
    double getPower() const { return power; }

    bool setBrand(const std::string& brand);
    bool setCylinders(int cylinders);
    bool setPower(double power);

    void changePower(double delta);

    bool Init(const std::string& brand, int cylinders, double power);
    void Read();
    void Display() const;
    std::string toString() const;
};
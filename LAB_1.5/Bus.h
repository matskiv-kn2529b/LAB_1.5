#pragma once
#include "Car.h"
#include <string>
#include <windows.h>

class Bus {
private:
    Car car;
    int seats;

public:
    Car getCar() const { return car; }
    int getSeats() const { return seats; }

    bool setCar(const Car& car);
    bool setSeats(int seats);

    void changeBrand(const std::string& newBrand);
    void changeSeats(int seats);

    bool Init(const Car& car, int seats);
    void Read();
    void Display() const;
    std::string toString() const;
};
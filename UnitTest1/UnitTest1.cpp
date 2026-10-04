#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.5/Car.h"
#include "../Lab_1.5/Bus.h"
#include "../Lab_1.5/Car.cpp"
#include "../Lab_1.5/Bus.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(CarTests)
    {
    public:

        TEST_METHOD(TestCarInitValid)
        {
            Car car;
            bool result = car.Init("BMW", 6, 300.0);

            Assert::IsTrue(result);
            Assert::AreEqual(std::string("BMW"), car.getBrand());
            Assert::AreEqual(6, car.getCylinders());
            Assert::AreEqual(300.0, car.getPower());
        }

        TEST_METHOD(TestCarInitInvalid)
        {
            Car car;
            // Перевірка з некоректними даними (порожня марка, циліндри <= 0, потужність <= 0)
            bool result = car.Init("", -2, 0.0);

            Assert::IsFalse(result);
        }

        TEST_METHOD(TestCarChangePowerSuccess)
        {
            Car car;
            car.Init("Audi", 4, 200.0);
            car.changePower(50.0);

            Assert::AreEqual(250.0, car.getPower());
        }

        TEST_METHOD(TestCarChangePowerInvalid)
        {
            Car car;
            car.Init("Audi", 4, 200.0);
            car.changePower(-300.0); // Потужність не повинна впасти до <= 0

            Assert::AreEqual(200.0, car.getPower());
        }
    };

    TEST_CLASS(BusTests)
    {
    public:

        TEST_METHOD(TestBusInitValid)
        {
            Car car;
            car.Init("Volvo", 6, 350.0);

            Bus bus;
            bool result = bus.Init(car, 45);

            Assert::IsTrue(result);
            Assert::AreEqual(45, bus.getSeats());
            Assert::AreEqual(std::string("Volvo"), bus.getCar().getBrand());
        }

        TEST_METHOD(TestBusInitInvalidSeats)
        {
            Car car;
            car.Init("MAN", 6, 320.0);

            Bus bus;
            bool result = bus.Init(car, -10); // Кількість місць повинна бути > 0

            Assert::IsFalse(result);
        }

        TEST_METHOD(TestBusChangeBrand)
        {
            Car car;
            car.Init("Ikarus", 8, 280.0);

            Bus bus;
            bus.Init(car, 30);
            bus.changeBrand("Neoplan");

            Assert::AreEqual(std::string("Neoplan"), bus.getCar().getBrand());
        }

        TEST_METHOD(TestBusChangeSeatsInvalid)
        {
            Car car;
            car.Init("Mercedes", 6, 360.0);

            Bus bus;
            bus.Init(car, 50);
            bus.changeSeats(-5); // Спроба встановити від'ємну кількість місць

            Assert::AreEqual(50, bus.getSeats()); // Значення має залишитися 50
        }
    };
}
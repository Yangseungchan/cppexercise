#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Car
{
private:
    int gasolineGauge;

public:
    Car() : gasolineGauge(50) {}
    Car(int n) : gasolineGauge(n) {}
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;

public:
    HybridCar() : Car(50), electricGauge(50) {}
    HybridCar(int n) : Car(n), electricGauge(n) {}
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;

public:
    HybridWaterCar() : HybridCar(50), waterGauge(50) {}
    HybridWaterCar(int n) : HybridCar(n), waterGauge(n) {}
    void ShowCurrentGauge()
    {
        cout << "잔여 가솔린 : " << GetGasGauge() << endl;
        cout << "잔여 전기량 : " << GetElecGauge() << endl;
        cout << "잔여 워터량 : " << waterGauge << endl;
    }
};

int main(void)
{
    HybridWaterCar car1;

    HybridWaterCar car2(75);

    car1.ShowCurrentGauge();

    cout << endl;

    car2.ShowCurrentGauge();
    return 0;
}
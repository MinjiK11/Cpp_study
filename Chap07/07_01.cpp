#include <iostream>
 
using namespace std;

class Car{
    private:
        int gasolineGauge;
    public:
        Car()
            :gasolineGauge(20){
            cout<<"gasoline: "<<gasolineGauge<<endl;
        }

        int GetGasGauge(){
            return gasolineGauge;
        }
};

class HybridCar : public Car{
    private:
        int electricGauge;
    public:
        HybridCar()
            :electricGauge(30){
            cout<<"electricity: "<<electricGauge<<endl;
        }

        int GetElecGauge(){
            return electricGauge;
        }
};

class HybridWaterCar : public HybridCar{
    private:
        int waterGauge;
    public:
        HybridWaterCar()
            :waterGauge(40){
            cout<<"water: "<<waterGauge<<endl;
        }

        void showCurrentGauge(){
            cout<<"left Gasoline: "<<GetGasGauge()<<endl;
            cout<<"left Electricity: "<<GetElecGauge()<<endl;
            cout<<"left Water: "<<waterGauge<<endl;
        }
};

int main(){
    HybridWaterCar car;
    car.showCurrentGauge();
}
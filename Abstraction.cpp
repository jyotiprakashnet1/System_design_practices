#include<iostream>
#include<string>

using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
    virtual void gearShift(int gear) = 0;
    virtual void brake() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string a, string m){
        this->brand = a;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model <<" : Engine start with a roar!" << endl;
    }

    void gearShift(int gear){
        if(!isEngineOn){
            cout << brand << " " << model <<" : Engine off! Cannot shift gear" << endl;
        }
        currentGear = gear;
        cout << brand << " " << model <<" : shifted to gear " << currentGear << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model <<" : Engine off! Cannot accelerate" << endl;
        }
        currentSpeed += 20;
        cout << brand << " " << model <<" : accelearting to " << currentSpeed << endl;
    }
    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed=0;
        cout << brand << " " << model <<" : breaking speed is now " << currentSpeed << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model <<" : Engine turned off. " << endl;
    }
};

int main(){
    Car* myCar = new SportsCar("Ford", "Mustang");
    myCar->startEngine();
    myCar->gearShift(1);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;
}
#include <iostream>
using namespace std;

//Component
class Car {
public:
	virtual float CalculateCost() = 0;
};

//Concrete Component
class DefaultCar : public Car {
private:
	float costOfWheels = 4;
	float costOfChassis = 10;
	float costOfEngine = 30;
public:
	float CalculateCost() {
		return costOfWheels + costOfChassis + costOfEngine;
	}
};

//Decorator
class Decorator : public Car {
protected:
	Car* car;
public:
	Decorator(Car* paramCar) {
		car = paramCar;
	}
	virtual float CalculateCost() = 0;
};

//Concrete Decorator
class GPSDecorator : public Decorator {
private:
	float costOfGpsDevice = 9.5;
public:
	GPSDecorator(Car* paramCar) : Decorator(paramCar) {}
	float CalculateCost() {
		return car->CalculateCost() + costOfGpsDevice;
	}
};

class SafeDecorator : public Decorator {
private:
	float costOfSafeSensors = 15;
public:
	SafeDecorator(Car* paramCar) : Decorator(paramCar) {}
	float CalculateCost() {
		return car->CalculateCost() + costOfSafeSensors;
	}
};

class HifiDecorator : public Decorator {
private:
	float costOfSpeaker = 8;
	float costOfAmpli = 14;
public:
	HifiDecorator(Car* paramCar) : Decorator(paramCar) {}
	float CalculateCost() {
		return car->CalculateCost() + costOfSpeaker + costOfAmpli;
	}
};

class AutoDecorator : public Decorator {
private:
	float costOfAutoProcessor = 20;
public:
	AutoDecorator(Car* paramCar) : Decorator(paramCar) {}
	float CalculateCost() {
		return car->CalculateCost() + costOfAutoProcessor;
	}
};

//Client
void main() {
	Car* defaultCar = new DefaultCar(); 
	Car* safeCar = new SafeDecorator(defaultCar); 
	Car* GPSAndSafeCar = new GPSDecorator(safeCar); 
	Car* HifiAndGPSAndSafeCar = new HifiDecorator(GPSAndSafeCar);
	Car* AutoAndHifiAndGPSAndSafeCar = new AutoDecorator(HifiAndGPSAndSafeCar);

	cout << "Cost of Default car: " << defaultCar->CalculateCost() << endl;
	cout << "Cost of Safe car: " << safeCar->CalculateCost() << endl;
	cout << "Cost of GPS and Safe car: " << GPSAndSafeCar->CalculateCost() << endl;
	cout << "Cost of GPS and Safe and HiFi car: " << HifiAndGPSAndSafeCar->CalculateCost() << endl;
	cout << "Cost of Auto and GPS and Safe and HiFi car: " << AutoAndHifiAndGPSAndSafeCar->CalculateCost() << endl;

	delete defaultCar;
	delete safeCar;
	delete GPSAndSafeCar;
	delete HifiAndGPSAndSafeCar;
	delete AutoAndHifiAndGPSAndSafeCar;
}
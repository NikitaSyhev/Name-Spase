#include <iostream>
#include <algorithm> // подключили для соритировки
#include <vector>
#include<cmath>   // подключили для сортировки
#include "Printer.h"
#include <memory>



class Incrementer {
public:
	Incrementer(int x) : _x(x){}

	int operator()(int y) {
		return _x + y;
	}
	int operator()(int y, double z) {
		return _x + y + z;
	}


	int myFunc(int y) {
		const auto add = [this, y](int a) {   //this мы прокидываем, чтобы увидели _x ( самого себя передаем по ссылке, чтобы использоваться ) 
			return _x +y + a;
		};
		return add(5);
	}
private:
	int _x;
};



class IVehicle {
public:
	virtual int getSpeed() const = 0;
	virtual  void printType() = 0;
	~IVehicle() {};
private:

};

class Car :public IVehicle {
public:
	Car(int speed) : _speed(speed){}
	int getSpeed() const override {
		return _speed;
	}
	void printType() override {
		std::cout << "Car" << std::endl;
	}
private:
	int _speed;
};

class Tram :public IVehicle {
public:
	Tram(int speed) : _speed(speed){}
	int getSpeed() const override {
		return _speed;
	}
	void printType() override {
		std::cout << "Tram" << std::endl;
	}
private:
	int _speed;
};

class Bus :public IVehicle {
public:
	Bus(int speed) : _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	void printType() override {
		std::cout << "Bus" << std::endl;
	}
private:
	int _speed;
};



int main() {
	using namespace Engine;
	//Функторы - объект, у кооторого пререгружен оператор (), по другому это функция которая хранит в себе данные 

	Incrementer inc(50);

	int a = inc(5);
	std::cout << a << std::endl;


	//лямбда -  безымянные локальные функции, которые можно создавать прямо внутри какого-либо выражения.
   //capture clause - [] ( название )
	const auto myinc = [=, &a](int number) ->int //за счет -> мы проказываем какой тип данных вернем ( особенность )
	{
		return number + 5 + a;
	};



	std::cout << myinc(6) << std::endl;
	//можно определить захват по умолчанию [=], все переменные которые видит myinc нужно захватить копированием, через , можно передать исключительный 
	// объект по ссылке (&)


	//[&total, factor]
	//[factor, &total]
	//[&, factor]
	//[=, &total]

	std::cout << inc.myFunc(3) << std::endl;
	std::cout << "=========================\n";

	std::vector<int> vec{ 1, -4, 3, -2 };
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	};
	std::cout << std::endl;

	//for (const auto el:vec){   - способ вывода вектора
	//std::cout << el << " "};
	//std::cout << endl;


	std::sort(vec.begin(), vec.end());
	for (const auto el : vec) {
		std::cout << el << " ";

	};

	std::cout << std::endl;

	// сортировка по модулю

	std::sort(vec.begin(), vec.end(), [](int a, int b) {   
		return std::abs(a) > std::abs(b);  // abs взять число по модулю
		});
	for (const auto el : vec) {
		std::cout << el << " ";
	}


	std::cout << std::endl;




	

	// Умные указатели
	std::shared_ptr<IVehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehicle speed" << v->getSpeed() << std::endl;
	v->printType();
	std::cout << "=============" << std::endl;






}
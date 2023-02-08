#include <iostream>
#include <algorithm> // ���������� ��� �����������
#include <vector>
#include<cmath>   // ���������� ��� ����������
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
		const auto add = [this, y](int a) {   //this �� �����������, ����� ������� _x ( ������ ���� �������� �� ������, ����� �������������� ) 
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
	//�������� - ������, � ��������� ����������� �������� (), �� ������� ��� ������� ������� ������ � ���� ������ 

	Incrementer inc(50);

	int a = inc(5);
	std::cout << a << std::endl;


	//������ -  ���������� ��������� �������, ������� ����� ��������� ����� ������ ������-���� ���������.
   //capture clause - [] ( �������� )
	const auto myinc = [=, &a](int number) ->int //�� ���� -> �� ����������� ����� ��� ������ ������ ( ����������� )
	{
		return number + 5 + a;
	};



	std::cout << myinc(6) << std::endl;
	//����� ���������� ������ �� ��������� [=], ��� ���������� ������� ����� myinc ����� ��������� ������������, ����� , ����� �������� �������������� 
	// ������ �� ������ (&)


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

	//for (const auto el:vec){   - ������ ������ �������
	//std::cout << el << " "};
	//std::cout << endl;


	std::sort(vec.begin(), vec.end());
	for (const auto el : vec) {
		std::cout << el << " ";

	};

	std::cout << std::endl;

	// ���������� �� ������

	std::sort(vec.begin(), vec.end(), [](int a, int b) {   
		return std::abs(a) > std::abs(b);  // abs ����� ����� �� ������
		});
	for (const auto el : vec) {
		std::cout << el << " ";
	}


	std::cout << std::endl;




	

	// ����� ���������
	std::shared_ptr<IVehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehicle speed" << v->getSpeed() << std::endl;
	v->printType();
	std::cout << "=============" << std::endl;






}
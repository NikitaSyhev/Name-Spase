#pragma once
#include <iostream>
#include <vector>


namespace Engine {
	class Printer
	{
	public:

		void getType(std::shared_ptr<IVehicle> p) {
			_vec.push_back(p);
		}
		void printVehicle(std::vector<IVehicle> & vec ) {
			
		}

	private:
		std::vector<std::shared_ptr<IVehicle>> _vec; // поле умных указателей
	};

	
}

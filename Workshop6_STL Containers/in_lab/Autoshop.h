// Workshop 6 - STL Containers
//
// Autoshop.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_AUTOSHOP_H
#define SAFE_AUTOSHOP_H
#include "Vehicle.h"
#include <vector>

namespace sdds
{
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		//prevent memory leak
		~Autoshop();
	};
}

#endif
// Workshop 6 - STL Containers
//
// Racecar.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_RACECAR_H
#define SAFE_RACECAR_H
#include "Car.h"

namespace sdds
{
	class Racecar : public Car {
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif
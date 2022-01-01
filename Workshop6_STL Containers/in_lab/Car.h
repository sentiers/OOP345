// Workshop 6 - STL Containers
//
// Car.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_CAR_H
#define SAFE_CAR_H
#include"Vehicle.h"
#include <iomanip>
#include <fstream>

namespace sdds
{
	class Car : public Vehicle {
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
		std::string getField(std::string & str);
	public:
		Car(std::istream &is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream &out) const;
	};
}

#endif
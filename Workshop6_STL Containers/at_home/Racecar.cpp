// Workshop 6 - STL Containers
//
// Racecar.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) :Car::Car(in) {
		std::string temp;
		std::getline(in, temp, ',');
		m_booster = std::stod(getField(temp));
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return (Car::topSpeed() * (1 + m_booster));
	}
}
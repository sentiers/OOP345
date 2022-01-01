// Workshop 6 - STL Containers
//
// Car.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"

namespace sdds
{
	Car::Car(std::istream &is) {
		std::string temp;
		std::getline(is, temp, ',');
		m_maker = getField(temp);

		std::getline(is, temp, ',');
		m_condition = getField(temp);

		if (m_condition == "" || m_condition == "n")
			m_condition = "new";
		else if (m_condition == "u")
			m_condition = "used";
		else if (m_condition == "b")
			m_condition = "broken";
		else
			throw "Invalid record!";

		try {
			std::getline(is, temp, ',');
			m_topSpeed = std::stod(getField(temp));
		}
		catch (...) {
			throw "Invalid record!";
		}

	}

	std::string Car::getField(std::string & str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	std::string Car::condition() const {
		return m_condition;
	}

	double Car::topSpeed() const {
		return m_topSpeed;
	}

	void Car::display(std::ostream &out) const {
		std::cout << "| "
			<< std::setw(10) << std::right << m_maker << " | "
			<< std::setw(6) << std::left << condition() << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}
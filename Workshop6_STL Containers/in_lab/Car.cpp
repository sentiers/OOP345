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
		std::getline(is, temp);

		m_maker = getField(temp);
		m_condition = getField(temp);
		m_topSpeed = std::stod(getField(temp));
	}

	std::string Car::getField(std::string & str) {
		int endPoint = 0;
		std::string field = "";
		str.erase(0, str.find_first_not_of(" "));
		if (str.find(' ') != std::string::npos) {
			endPoint = str.find(',');
			field = str.substr(0, endPoint);
			field.erase(field.find_last_not_of(" ") + 1, endPoint + 1);
			str.erase(0, endPoint + 1);
		}
		else {
			str.erase(str.find_last_not_of(" ") + 1);
			field = str;
		}
		return field;
	}

	std::string Car::condition() const {
		std::string condition = "";
		if (m_condition == "n")
			condition = "new";
		else if (m_condition == "u")
			condition = "used";
		else if (m_condition == "b")
			condition = "broken";

		return condition;
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
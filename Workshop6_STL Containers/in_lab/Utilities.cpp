// Workshop 6 - STL Containers
//
// Utilities.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"
#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in) {

		std::string temp;
		char type;
		char delimiter;

		std::getline(in, temp);
		std::stringstream ss(temp);
		ss >> type >> delimiter;

		if (ss) {
			switch (type) {
			case 'c':
			case 'C':
				return new Car(ss);
				break;
			default:
				throw "Invalid " + type;
				break;
			}
		}else {
			return nullptr;
		}
	}
}
// Workshop 6 - STL Containers
//
// Utilities.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_UTILITIES_H
#define SAFE_UTILITIES_H
#include "Vehicle.h"
#include <sstream>

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif
// Milestone 3
//
// Station.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/4/5
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_STATION_H
#define SAFE_STATION_H
#include <iomanip>
#include "Utilities.h"

class Station {
	unsigned int m_id;
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	static size_t m_widthField;
	static size_t id_generator;

public:
	Station(const std::string& str);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif
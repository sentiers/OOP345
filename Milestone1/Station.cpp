// Milestone 1
//
// Station.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/22
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Station.h"

size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station(std::string &str) {
	Utilities u;
	size_t pos = 0;
	bool more = false;

	m_id = ++id_generator;
	m_name = u.extractToken(str, pos, more);
	m_serialNumber = stoi(u.extractToken(str, pos, more));
	m_quantity = stoi(u.extractToken(str, pos, more));
	m_description = u.extractToken(str, pos, more);

	if (m_widthField < u.getFieldWidth()) {
		m_widthField = u.getFieldWidth();
	}
}

const std::string& Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	return m_serialNumber++;
}

unsigned int Station::getQuantity() const {
	return m_quantity;
}

void Station::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity--;
	}
}

void Station::display(std::ostream &os, bool full) const {

	os << "[" << std::setw(3) << std::setfill('0') << m_id << "]"
		<< " Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name
		<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]";
	if (full) {
		os << " Quantity: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_quantity
			<< std::right << " Description: " << m_description;
	}
	os << std::endl;
}
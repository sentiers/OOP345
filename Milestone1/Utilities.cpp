// Milestone 1
//
// Utilities.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/22
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

size_t Utilities::m_widthField = 1;
char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string temp = str.substr(next_pos);
	size_t position = temp.find(getDelimiter());

	if (position != std::string::npos) {
		temp = temp.substr(0, position);
		next_pos += position + 1;
		more = true;

		if (m_widthField < temp.length()) {
			setFieldWidth(temp.length());
		}
	}
	else {
		more = false;
	}

	if (temp.length() == 0) {
		throw "No Token";
	}

	return temp;
}

void Utilities::setDelimiter(const char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}

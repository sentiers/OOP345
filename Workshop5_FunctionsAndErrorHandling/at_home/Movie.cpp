// Workshop 5 - Functions and Error Handling
//
// Movie.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace sdds
{
	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_summary = "";
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	std::string Movie::getField(std::string & str) {
		int endPoint = 0;
		std::string field = "";
		str.erase(0, str.find_first_not_of(" "));
		endPoint = str.find(',');
		field = str.substr(0, endPoint);
		field.erase(field.find_last_not_of(" ") + 1, endPoint + 1);
		str.erase(0, endPoint + 1);
		return field;
	}

	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;
		m_title = getField(temp);
		m_year = std::stoi(getField(temp));
		
		temp.erase(0, temp.find_first_not_of(" "));
		temp.erase(temp.find_last_not_of(" ") + 1);

		m_summary = temp;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.m_title << " | "
			<< std::setw(4) << movie.m_year << " | "
			<< movie.m_summary
			<< std::endl;

		return os;
	}
}


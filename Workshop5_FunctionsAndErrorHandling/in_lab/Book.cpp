// Workshop 5 - Functions and Error Handling
//
// Book.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Book.h"
#include <string>
#include <iomanip>

namespace sdds
{
	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0.00;
		m_summary = "";
	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}

	std::string Book::getField(std::string & str) {
		int endPoint = 0;
		std::string field = "";
		str.erase(0, str.find_first_not_of(" "));
		endPoint = str.find(',');
		field = str.substr(0, endPoint);
		field.erase(field.find_last_not_of(" ") + 1, endPoint + 1);
		str.erase(0, endPoint + 1);
		return field;
	}

	Book::Book(const std::string& strBook) {
		std::string temp = strBook;

		m_author = getField(temp);
		m_title = getField(temp);
		m_country = getField(temp);
		m_price = std::stod(getField(temp));
		m_year = std::stoi(getField(temp));

		temp.erase(0, temp.find_first_not_of(" "));
		temp.erase(temp.find_last_not_of(" ") + 1);

		m_summary = temp;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::setw(20) << book.m_author << " | "
			<< std::setw(22) << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | "
			<< book.m_summary
			<< std::endl;
		return os;
	}
}
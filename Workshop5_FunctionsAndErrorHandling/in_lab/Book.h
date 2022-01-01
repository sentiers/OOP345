// Workshop 5 - Functions and Error Handling
//
// Book.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_BOOK_H
#define SAFE_BOOK_H
#include <iostream>

namespace sdds
{
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_summary;
		std::string getField(std::string& str);

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& os, const Book& book);

	};
}

#endif
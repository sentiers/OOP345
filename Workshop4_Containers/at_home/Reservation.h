// Workshop 4 - Containers
//
// Reservation.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/8
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_RESERVATION_H
#define SAFE_RESERVATION_H
#include <iostream>

namespace sdds
{
	class Reservation {
		std::string m_reservId;
		std::string m_reservName;
		std::string m_email;
		int m_peopleNum;
		int m_day;
		int m_hour;

	public:
		Reservation();
		Reservation(const std::string& reserv);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
	};
}

#endif
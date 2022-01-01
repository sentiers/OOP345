// Workshop 4 - Containers
//
// Reservation.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/5
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Reservation.h"

namespace sdds
{
	Reservation::Reservation() {
		m_reservId = "";
		m_reservName = "";
		m_email = "";
		m_peopleNum = 0;
		m_day = 0;
		m_hour = 0;
	}

	Reservation::Reservation(const std::string& res) {

		std::string temp = res;

		//removing whitespaces
		while (temp.find(' ') != std::string::npos)
			temp.erase(std::find(temp.begin(), temp.end(), ' '));

		//set the end points
		int reservId_endPoint = temp.find(':');
		int reservName_endPoint = temp.find(',');
		int email_endPoint = temp.find(',', reservName_endPoint + 1);
		int peopleNum_endPoint = temp.find(',', email_endPoint + 1);
		int day_endPoint = temp.find(',', peopleNum_endPoint + 1);
		int hour_endPoint = temp.length();

		//get values for each fields
		m_reservId = temp.substr(0, reservId_endPoint);
		m_reservName = temp.substr(reservId_endPoint + 1, reservName_endPoint - reservId_endPoint - 1);
		m_email = temp.substr(reservName_endPoint + 1, email_endPoint - reservName_endPoint - 1);
		m_peopleNum = std::stoi(temp.substr(email_endPoint + 1, peopleNum_endPoint - email_endPoint - 1));
		m_day = std::stoi(temp.substr(peopleNum_endPoint + 1, day_endPoint - peopleNum_endPoint - 1));
		m_hour = std::stoi(temp.substr(day_endPoint + 1, hour_endPoint - day_endPoint - 1));
	}

	std::ostream &operator<<(std::ostream &os, const Reservation& r) {

		std::string email_bracket = "<" + r.m_email + ">";
		std::string tmp;

		if (r.m_hour >= 6 && r.m_hour <= 9)
			tmp = "Breakfast on day";
		else if (r.m_hour >= 11 && r.m_hour <= 15)
			tmp = "Lunch on day";
		else if (r.m_hour >= 17 && r.m_hour <= 21)
			tmp = "Dinner on day";
		else
			tmp = "Drinks on day";

		os << "Reservation " << r.m_reservId << ": "
			<< std::setw(10) << std::right << r.m_reservName << "  "
			<< std::setw(20) << std::left << email_bracket << "    "
			<< tmp << " "
			<< r.m_day << " @ "
			<< r.m_hour << ":00 for "
			<< r.m_peopleNum << " people."
			<< std::endl;

		return os;
	}
}
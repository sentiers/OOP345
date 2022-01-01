// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
//
// event.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/18
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned int g_sysClock = 0;

namespace sdds
{
	Event::Event() {
		safeState();
	}

	Event::Event(const Event& e) {
		if (e.m_desciption != nullptr) {
			m_seconds = e.m_seconds;

			int length = strlen(e.m_desciption) + 1;
			m_desciption = new char[length];
			strncpy(m_desciption, e.m_desciption, length);

// *this = e;
		}
		else {
			m_desciption = nullptr;
		}
	}

	Event &Event::operator=(const Event& e) {
		if (this != &e && e.m_desciption) {
			m_seconds = e.m_seconds;

			delete[] m_desciption;

			int length = strlen(e.m_desciption) + 1;
			m_desciption = new char[length];
			strncpy(m_desciption, e.m_desciption, length);
		}
		return *this;
	}

	Event::~Event() {
		delete[] m_desciption;
		safeState();
	}

	void Event::safeState() {
		m_seconds = 0;
		m_desciption = nullptr;
	}

	void Event::display() {

		//variable that remains in memory for the lifetime of the program
		static int counter = 0;

		int hour = 0;
		int min = 0;
		int sec = 0;

		//   1.
		//   2.
		std::cout << std::setfill(' ') << std::setw(3) << ++counter << ". ";

		if (m_desciption == nullptr) {
			std::cout << "[ No Event ]" << std::endl;
		}
		else {
			//1 hour = 3600 seconds
			//total seconds / 3600 seconds = total hours
			hour = m_seconds / 3600;

			//1 minutes = 60 seconds
			//total seconds / 60 seconds = total minutes
			//total minutes % 60 = remainder minutes
			min = (m_seconds / 60) % 60;

			//total seconds % 60 = remainder seconds
			sec = m_seconds % 60;

			//HH:MM:SS -> DESCRIPTION
			std::cout << std::setfill('0') << std::setw(2) << hour << ":"
				<< std::setfill('0') << std::setw(2) << min << ":"
				<< std::setfill('0') << std::setw(2) << sec << " -> "
				<< m_desciption << std::endl;
		}
	}

	void Event::setDescription(const char* des) {

		if (des == nullptr || des[0] == '\0') {
			safeState();
		}
		else {
			m_seconds = g_sysClock;

			int length = strlen(des) + 1;
			m_desciption = new char[length];
			strncpy(m_desciption, des, length);
		}
	}
}
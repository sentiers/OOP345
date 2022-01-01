// Workshop 2 - Copy and Move Semantics
//
// TimedEvents.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "TimedEvents.h"
#include <string>

namespace sdds
{
	TimedEvents::TimedEvents() {
		m_recordNum = 0;
	}

	void TimedEvents::startClock() {
		m_start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		m_end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* eName) {
		auto nano = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start);

		if (m_recordNum < max_num) {
			m_record[m_recordNum].eventName = eName;
			m_record[m_recordNum].units = "nanoseconds";
			m_record[m_recordNum].duration = nano;
		}
		m_recordNum++;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& te) {

		return te.noFriend(os);
	}

	std::ostream& TimedEvents::noFriend(std::ostream& os)const {
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;

		for (int i = 0; i < m_recordNum; i++) {
			os << std::setw(20) << std::left << m_record[i].eventName;
			os << std::setw(12) << std::right << m_record[i].duration.count() << ' ';
			os << m_record[i].units << std::endl;
		}
		os << "--------------------------" << std::endl;

		return os;
	}
}
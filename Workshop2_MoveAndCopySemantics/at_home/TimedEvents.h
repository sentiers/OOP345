// Workshop 2 - Copy and Move Semantics
//
// TimedEvents.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/26
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_TIMEDEVENTS_H
#define SAFE_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <chrono>

namespace sdds
{
	const int max_num = 7;

	class TimedEvents {
		int m_recordNum;
		std::chrono::steady_clock::time_point m_start;
		std::chrono::steady_clock::time_point m_end;
		struct {
			std::string eventName;
			std::string units;
			std::chrono::steady_clock::duration duration;
		}m_record[max_num];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* eName);
		std::ostream& noFriend(std::ostream& os = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& os, const TimedEvents& te);
}
#endif
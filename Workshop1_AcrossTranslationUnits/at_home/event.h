// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
//
// event.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/18
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_EVENT_H
#define SAFE_EVENT_H

//global variable
extern unsigned int g_sysClock;

namespace sdds
{
	class Event {
		unsigned int m_seconds;
		char * m_desciption;
		void safeState();

	public:
		Event();
		Event(const Event& e);
		Event& operator = (const Event& e);
		virtual ~Event();
		void display();
		void setDescription(const char* des);
	};
}
#endif
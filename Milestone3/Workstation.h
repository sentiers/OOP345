// Milestone 3
//
// Workstation.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/4/5
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_WORKSTATION_H
#define SAFE_WORKSTATION_H
#include "CustomerOrder.h"
#include <deque>

class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

public:
	Workstation(const std::string&);

	Workstation(Workstation&) = delete;
	Workstation& operator =(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator =(Workstation&&) = delete;

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&);
	Workstation& operator += (CustomerOrder&&);
};

#endif

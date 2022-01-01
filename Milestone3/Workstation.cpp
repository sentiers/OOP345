// Milestone 3
//
// Workstation.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/4/5
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Workstation.h"

Workstation::Workstation(const std::string& str) : Station(str) {
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.back().isOrderFilled()) {
			m_orders.back().fillItem(*this, os);
		}
	}
}

bool Workstation::moveOrder() {
	bool move = false;
	if (!m_orders.empty()) {
		if (m_pNextStation && m_orders.back().isItemFilled(getItemName())) {
			*m_pNextStation += std::move(m_orders.back());
			m_orders.pop_back();
			move = true;
		}
	}
	return move;
}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = (Workstation*)&station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& src) {
	bool complete = false;
	if (!m_orders.empty() && m_orders.back().isOrderFilled()) {
		src = std::move(m_orders.back());
		m_orders.pop_back();
		complete = true;
	}
	return complete;
}

void Workstation::display(std::ostream& os) {
	os << this->getItemName() << " --> "
		<< ((m_pNextStation == nullptr) ? "END OF LINE" : m_pNextStation->getItemName())
		<< std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& src) {
	m_orders.push_front(std::move(src));
	return *this;
}
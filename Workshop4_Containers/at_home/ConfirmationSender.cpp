// Workshop 4 - Containers
//
// ConfirmationSender.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/8
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender::ConfirmationSender() {
		m_reserv = nullptr;
		m_confirmNum = 0;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& confirmation) {
		*this = confirmation;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender &&confirmation) {
		*this = std::move(confirmation);
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_reserv;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& reservation) {
		bool isSame = false;

		for (size_t i = 0; i < m_confirmNum; i++) {
			if (m_reserv[i] == &reservation) {
				isSame = true;
			}
		}

		if (!isSame) {
			const Reservation** temp = new const Reservation*[m_confirmNum + 1];
			for (size_t i = 0; i < m_confirmNum; ++i) {
				temp[i] = m_reserv[i];
			}

			temp[m_confirmNum] = &reservation;
			m_confirmNum++;

			delete[] m_reserv;
			m_reserv = temp;
		}
		return *this;
	}

	ConfirmationSender &ConfirmationSender::operator-=(const Reservation& reservation) {
		for (size_t i = 0; i < m_confirmNum; i++) {
			if (m_reserv[i] == &reservation) {
				m_reserv[i] = nullptr;
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator = (const ConfirmationSender& confirmation) {
		if (this != &confirmation) {
			delete[] m_reserv;
			m_reserv = nullptr;

			m_confirmNum = confirmation.m_confirmNum;
			m_reserv = new const Reservation*[m_confirmNum];
			for (size_t i = 0; i < m_confirmNum; i++) {
				m_reserv[i] = confirmation.m_reserv[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator = (ConfirmationSender&& confirmation) {
		if (this != &confirmation) {
			delete[] m_reserv;
			m_reserv = nullptr;

			m_reserv = confirmation.m_reserv;
			m_confirmNum = confirmation.m_confirmNum;
			confirmation.m_confirmNum = 0;
			confirmation.m_reserv = nullptr;
		}
		return *this;
	}

	std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirmation) {

		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (confirmation.m_reserv == nullptr) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < confirmation.m_confirmNum; i++) {
				if (confirmation.m_reserv[i] != nullptr) {
					os << *confirmation.m_reserv[i];
				}
			}
		}
		os << "--------------------------" << std::endl;
		return  os;
	}
}

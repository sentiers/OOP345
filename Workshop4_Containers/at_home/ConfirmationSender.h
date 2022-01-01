// Workshop 4 - Containers
//
// ConfirmationSender.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/8
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_CONFIRMATIONSENDER_H
#define SAFE_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender {

		const Reservation** m_reserv = nullptr;
		size_t m_confirmNum = 0;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& confirmation);
		ConfirmationSender(ConfirmationSender&& confirmation);
		virtual ~ConfirmationSender();

		ConfirmationSender& operator+=(const Reservation& reservation);
		ConfirmationSender& operator-=(const Reservation& reservation);

		ConfirmationSender& operator = (const ConfirmationSender& confirmation);
		ConfirmationSender& operator = (ConfirmationSender&& confirmation);

		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirmation);
	};
}

#endif
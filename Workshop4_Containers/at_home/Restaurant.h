// Workshop 4 - Containers
//
// Restaurant.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/8
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_RESTAURANT_H
#define SAFE_RESTAURANT_H
#include "Reservation.h"

namespace sdds
{
	class Restaurant {

		Reservation* m_reserv = nullptr;
		size_t m_reservNum = 0;

	public:
		Restaurant();
		Restaurant(const Restaurant& restaurant);
		Restaurant(Restaurant&& restaurant);
		Restaurant(Reservation* reservation[], size_t cnt);
		virtual ~Restaurant();

		size_t size() const;

		Restaurant& operator = (const Restaurant& restaurant);
		Restaurant& operator = (Restaurant&& restaurant);

		friend std::ostream& operator << (std::ostream& os, const Restaurant& restaurant);
	};
}

#endif
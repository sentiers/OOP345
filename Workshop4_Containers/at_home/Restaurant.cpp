// Workshop 4 - Containers
//
// Restaurant.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/8
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant() {
		m_reserv = nullptr;
		m_reservNum = 0;
	}

	Restaurant::Restaurant(const Restaurant& restaurant) {
		*this = restaurant;
	}

	Restaurant::Restaurant(Restaurant&& restaurant) {
		*this = std::move(restaurant);
	}

	Restaurant::Restaurant(Reservation *reservation[], size_t cnt) {
		m_reserv = nullptr;
		m_reservNum = 0;

		m_reserv = new Reservation[cnt];

		if (reservation) {
			for (size_t i = 0; i < cnt; i++) {
				m_reserv[i] = *reservation[i];

			}
			m_reservNum = cnt;
		}
	}

	Restaurant::~Restaurant() {
		delete[] m_reserv;
	}

	size_t Restaurant::size() const {
		return m_reservNum;
	}

	Restaurant& Restaurant::operator = (const Restaurant& restaurant) {

		if (this != &restaurant) {
			delete[] m_reserv;
			m_reserv = nullptr;

			m_reservNum = restaurant.m_reservNum;
			m_reserv = new Reservation[m_reservNum];

			for (size_t i = 0; i < m_reservNum; i++) {
				m_reserv[i] = restaurant.m_reserv[i];

			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator = (Restaurant&& restaurant) {

		if (this != &restaurant) {
			delete[] m_reserv;
			m_reserv = nullptr;

			m_reservNum = restaurant.m_reservNum;
			m_reserv = restaurant.m_reserv;
			restaurant.m_reservNum = 0;
			restaurant.m_reserv = nullptr;
		}
		return *this;
	}

	std::ostream& operator << (std::ostream& os, const Restaurant& restaurant) {

		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;

		if (restaurant.size() == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < restaurant.m_reservNum; i++) {
				os << restaurant.m_reserv[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
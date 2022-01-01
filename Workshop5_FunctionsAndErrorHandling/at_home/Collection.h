// Workshop 5 - Functions and Error Handling
//
// Collection.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_COLLECTION_H
#define SAFE_COLLECTION_H
#include <iostream>
#include <stdexcept>
#include <string>

namespace sdds
{
	template<typename T>
	class Collection {
		std::string m_name;
		T* m_items = nullptr;
		size_t m_size = 0;
		void(*collectionObserver) (const Collection&, const T&) = nullptr;

	public:
		Collection(std::string name) {
			m_name = name;
			m_items = nullptr;
			m_size = 0;
			collectionObserver = nullptr;
		}

		Collection(const Collection&) = delete;
		Collection& operator = (const Collection&) = delete;

		virtual ~Collection() {
			delete[] m_items;
		}

		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void(*observer)(const Collection<T>&, const T&)) {
			collectionObserver = observer;
		};

		Collection<T>& operator+=(const T& item) {
			bool isSame = false;
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == item.title()) {
					isSame = true;
				}
			}

			if (!isSame) {
				T* temp = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++) {
					temp[i] = m_items[i];
				}

				temp[m_size] = item;
				m_size++;

				delete[] m_items;
				m_items = temp;

				if (collectionObserver != nullptr)
					collectionObserver(*this, item);
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				throw std::out_of_range("Bad index ["
					+ std::to_string(idx)
					+ "]. Collection has ["
					+ std::to_string(m_size)
					+ "] items.");
			}
			return m_items[idx];
		}

		T* operator[] (std::string title) const {
			T *temp = nullptr;
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == title) {
					temp = m_items + i;
				}
			}
			return temp;
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			os << collection[i];
		}
		return os;
	}

}
#endif
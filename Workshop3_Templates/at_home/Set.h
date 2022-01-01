// Workshop 3 - Templates
//
// Set.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/1
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_SET_H
#define SAFE_SET_H

namespace sdds
{
	template <typename T, size_t N>
	class Set {
		T array[N];
		size_t number = 0;

	public:
		size_t size() const {
			return number;
		}

		const T& operator[](size_t idx) const {
			return array[idx];
		}

		void operator+=(const T& item) {
			if (number < N) {
				array[number] = item;
				number++;
			}
		}
	};
}
#endif

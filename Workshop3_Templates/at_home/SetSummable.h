// Workshop 3 - Templates
//
// SetSummable.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/1
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_SETSUMMABLE_H
#define SAFE_SETSUMMABLE_H
#include "Set.h"
#include "PairSummable.h"

namespace sdds
{
	template <typename T, size_t N, typename K, typename V>
	class SetSummable : public Set<T, N> {

	public:
		V accumulate(const K& key) const {

			V sumValue = PairSummable<K, V>::getInitialValue();

			for (size_t i = 0; i < ((Set<T, N> &) *this).size(); i++) {
				sumValue = (*this)[i].sum(key, sumValue);
			}
			return sumValue;

		}
	};
}
#endif
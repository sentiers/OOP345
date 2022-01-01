// Workshop 3 - Templates
//
// PairSummable.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/1
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_PAIRSUMMABLE_H
#define SAFE_PAIRSUMMABLE_H
#include "Pair.h"

namespace sdds
{
	template<typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V initialValue;
		static size_t minWidth;

	public:

		static const V& getInitialValue() {
			return initialValue;
		}

		PairSummable() {}

		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
			if (minWidth < key.size()) {
				minWidth = key.size();
			}
		}

		V sum(const K& key, const V& val) const {

			return (key == Pair<K, V>::key()) ? (Pair<K, V> ::value() + val) : val;
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minWidth);
			Pair<K, V> ::display(os);
			os.unsetf(std::ios::left);
		}
	};

	template <typename K, typename V>
	size_t PairSummable<K, V>::minWidth = 0;

	template<>
	std::string PairSummable <std::string, std::string> ::initialValue = "";

	template<>
	int PairSummable <std::string, int> ::initialValue = 0;

	template<>
	std::string PairSummable <std::string, std::string>::sum(const std::string& key, const std::string& val) const {
		std::string temp = {};
		if (key == this->key()) {
			if (val.length()) {
				temp = val + ", " + Pair<std::string, std::string>::value();
			}
			else {
				temp = Pair<std::string, std::string>::value();
			}
		}
		else {
			temp = val;
		}
		return temp;
	}
}
#endif
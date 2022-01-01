// Workshop 3 - Templates
//
// Pair.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/1
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_PAIR_H
#define SAFE_PAIR_H

namespace sdds
{
	template<typename K, typename V>
	class Pair {
		K keyType;
		V valueType;

	public:
		Pair() {}

		Pair(const K& key, const V& value) {
			keyType = key;
			valueType = value;
		}

		const K& key() const {
			return keyType;
		}

		const V& value() const {
			return valueType;
		}

		virtual void display(std::ostream& os) const {
			os << keyType << " : " << valueType << std::endl;
		}

	};

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif

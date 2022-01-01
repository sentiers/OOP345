// Workshop 5 - Functions and Error Handling
//
// SpellChecker.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <string>
#include <fstream>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		std::string temp;

		for (size_t i = 0; i < 5; i++) {
			std::getline(file, temp);
			m_badWords[i] = temp.substr(0, temp.find(" "));
			temp.erase(0, temp.find(" "));
			temp.erase(0, temp.find_first_not_of(" "));
			m_goodWords[i] = temp;
		}
		file.close();
	}

	void SpellChecker::operator()(std::string& text) const {
		size_t index;
		for (size_t i = 0; i < 5; i++) {
			index = text.find(m_badWords[i]);
			while (index != std::string::npos) {
				text.replace(index, m_badWords[i].size(), m_goodWords[i]);
				index = text.find(m_badWords[i]);
			}
		}
	}

}


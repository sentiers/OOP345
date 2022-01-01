// Workshop 5 - Functions and Error Handling
//
// SpellChecker.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_SPELLCHECKER_H
#define SAFE_SPELLCHECKER_H
#include <iostream>

namespace sdds
{
	class SpellChecker {
		std::string m_badWords[5];
		std::string m_goodWords[5];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif
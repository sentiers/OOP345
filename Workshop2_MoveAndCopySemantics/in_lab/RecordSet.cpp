// Workshop 2 - Copy and Move Semantics
//
// RecordSet.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "RecordSet.h"

namespace sdds
{
	void RecordSet::safeState() {
		m_stringNum = 0;
		string = nullptr;
	}

	RecordSet::RecordSet() {
		safeState();
	}

	RecordSet::RecordSet(const std::string fName) {
		std::ifstream ifstr(fName.c_str());

		safeState();

		if (!ifstr) { return; }

		do {
			if (ifstr.get() == ' ') {
				m_stringNum++;
			}
		} while (!ifstr.eof());

		string = new std::string[++m_stringNum];

		ifstr.clear();
		ifstr.seekg(std::ios::beg);

		for (size_t i = 0; i < m_stringNum; i++) {
			std::getline(ifstr, string[i], ' ');
		}
	}

	RecordSet::RecordSet(const RecordSet& r) {
		if (r.string != nullptr) {

			m_stringNum = r.m_stringNum;
			string = new std::string[m_stringNum];

			for (size_t i = 0; i < m_stringNum; i++) {
				string[i] = r.string[i];
			}

		}
		else {
			string = nullptr;
		}
	}

	RecordSet& RecordSet::operator = (const RecordSet& r) {
		if (this != &r) {
			delete[] string;

			m_stringNum = r.m_stringNum;
			string = new std::string[m_stringNum];

			for (size_t i = 0; i < m_stringNum; i++) {
				string[i] = r.string[i];
			}
		}

		return *this;
	}

	RecordSet::~RecordSet() {
		delete[] string;
		safeState();
	}

	std::size_t RecordSet::size() {
		return m_stringNum;
	}

	std::string RecordSet::getRecord(std::size_t num) {
		std::string result;

		if (num < m_stringNum) {
			result = string[num];
		}
		else {
			result = "";
		}

		return result;
	}
}
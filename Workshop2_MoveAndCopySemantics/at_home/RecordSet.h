// Workshop 2 - Copy and Move Semantics
//
// RecordSet.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/26
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_RECORDSET_H
#define SAFE_RECORDSET_H

#include <iostream>
#include <fstream>
#include <string>

namespace sdds
{
	class RecordSet {
		std::size_t m_stringNum;
		std::string *string;
		void safeState();

	public:
		RecordSet();
		RecordSet(const std::string fName);
		RecordSet(const RecordSet& r);
		RecordSet& operator = (const RecordSet& r);
		~RecordSet();
		std::size_t size();
		std::string getRecord(std::size_t num);

		RecordSet(RecordSet&& R);
		RecordSet& operator = (RecordSet&& R);
	};
}
#endif
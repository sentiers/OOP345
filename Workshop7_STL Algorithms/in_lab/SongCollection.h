// Workshop 7 - STL Algorithms
//
// SongCollection.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_SONGCOLLECTION_H
#define SAFE_SONGCOLLECTION_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

namespace sdds
{
	struct Song {
		std::string s_artist;
		std::string s_title;
		std::string s_album;
		double s_price;
		std::string s_released;
		int s_length;
	};

	class SongCollection {
		std::vector<Song> m_song;
		std::string getField(std::string &str, int length);
	public:
		SongCollection(const std::string fileName);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif
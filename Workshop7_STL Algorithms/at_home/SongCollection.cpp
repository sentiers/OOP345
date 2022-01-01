// Workshop 7 - STL Algorithms
//
// SongCollection.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/18
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"

namespace sdds
{
	SongCollection::SongCollection(const std::string fileName) {
		std::ifstream file(fileName);
		if (!file)
			throw "Cannot open the file";

		while (!file.eof()) {
			std::string temp;
			std::getline(file, temp);
			Song song;

			song.s_title = getField(temp, 25);
			song.s_artist = getField(temp, 25);
			song.s_album = getField(temp, 25);
			song.s_released = getField(temp, 5);
			song.s_length = std::stoi(getField(temp, 5));
			song.m_price = std::stod(getField(temp, 5));

			m_song.push_back(song);
		}
	}

	std::string SongCollection::getField(std::string &str, int length) {
		std::string field = "";
		field = str.substr(0, length);
		field.erase(0, field.find_first_not_of(" "));
		field.erase(field.find_last_not_of(" ") + 1);
		str = str.substr(length);
		return field;
	}

	void SongCollection::display(std::ostream& out) const {
		int totalTime = 0;
		for_each(m_song.begin(), m_song.end(), [&](const Song& s) {
			out << s << std::endl;
			totalTime += s.s_length;
		});

		out << "----------------------------------------------------------------------------------------" << std::endl
			<< "|" << std::setw(78) << "Total Listening Time: "
			<< totalTime / 3600
			<< ":" << (totalTime % 3600) / 60
			<< ":" << totalTime % 60
			<< " |" << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::left << std::setw(20) << theSong.s_title
			<< " | " << std::setw(15) << theSong.s_artist
			<< " | " << std::setw(20) << theSong.s_album
			<< " | " << std::right << std::setw(6) << theSong.s_released
			<< " | " << theSong.s_length / 60
			<< ":" << ((theSong.s_length % 60 < 10) ? "0" : "") << theSong.s_length % 60
			<< " | " << theSong.m_price
			<< " |";
		return out;
	}

	void SongCollection::sort(std::string field) {
		if (field == "title") {
			std::sort(m_song.begin(), m_song.end(), [&](Song& a, Song& b) {
				return a.s_title < b.s_title;
			});
		}
		else if (field == "album") {
			std::sort(m_song.begin(), m_song.end(), [&](Song& a, Song& b) {
				return a.s_album < b.s_album;
			});
		}
		else if (field == "length") {
			std::sort(m_song.begin(), m_song.end(), [&](Song& a, Song& b) {
				return a.s_length < b.s_length;
			});
		}
	}

	void SongCollection::cleanAlbum() {
		for_each(m_song.begin(), m_song.end(), [&](Song& s) {
			if (s.s_album == "[None]")
				s.s_album = "";
		});
	}

	bool SongCollection::inCollection(std::string artist) const {
		return any_of(m_song.begin(), m_song.end(), [&](const Song& s) {
			return s.s_artist == artist;
		});
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const {
		std::list<Song> listSong;
		for_each(m_song.begin(), m_song.end(), [&](const Song& s) {
			if (s.s_artist == artist) {
				listSong.push_back(s);
			}
		});
		return listSong;
	}
}
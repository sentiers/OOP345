// Workshop 5 - Functions and Error Handling
//
// Movie.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_MOVIE_H
#define SAFE_MOVIE_H

namespace sdds
{
	class Movie {
		std::string m_title;
		size_t m_year;
		std::string m_summary;
		std::string getField(std::string& str);

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template <typename T>
		void fixSpelling(T spellchecker) {
			spellchecker(m_title);
			spellchecker(m_summary);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};	   	  
}
#endif
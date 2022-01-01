// Workshop 5 - Functions and Error Handling
//
// w5_home.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/2/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection, const Book& theBook) {
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection, const Movie& theMovie) {
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv) {

	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream file(argv[1]);
		size_t count = 0;

		std::string BookInfo;
		do {
			std::getline(file, BookInfo);
			if (file) {
				if (BookInfo[0] != '#') {
					library += sdds::Book(BookInfo);
					count++;
				}
			}
		} while (count < 4);

		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the books from the file.
		for (size_t i = 0; i < 3; i++) {
			std::getline(file, BookInfo);
			if (file) {
				library += sdds::Book(BookInfo);
			}
		}
		file.close();
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto UpdatedBookInfo = [&](Book& b)-> double {
		if (b.country() == "US") {
			return b.price() *= usdToCadRate;
		}
		else if (b.country() == "UK" && b.year() >= 1990 && b.year() <= 1999) {
			return b.price() *= gbpToCadRate;
		}
		else {
			return b.price();
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	for (size_t i = 0; i < 7; i++) {
		UpdatedBookInfo(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream file(argv[2]);
		size_t count = 0;

		std::string MovieInfo;
		do {
			std::getline(file, MovieInfo);
			if (file) {
				if (MovieInfo[0] != '#') {
					movies[count] = sdds::Movie(MovieInfo);
					count++;
				}
			}
		} while (count < 5);
		file.close();
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	// Add a few movies to collection; no observer is set
	((theCollection += movies[0]) += movies[1]) += movies[2];
	theCollection += movies[1];
	// add more movies; now we get a callback from the collection
	theCollection.setObserver(movieAddedObserver);
	theCollection += movies[3];
	theCollection += movies[3];
	theCollection += movies[4];
	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";

	// TODO: The following loop can generate generate an exception
	//         write code to handle the exception
	//       If an exception occurs print a message in the following format
	//EXCEPTION: ERROR_MESSAGE<endl>
	//         where ERROR_MESSAGE is extracted from the exception object.
	try {
		for (auto i = 0u; i < 10; ++i)
			std::cout << theCollection[i];
	}
	catch (const char* err) {
		std::cout << "EXCEPTION: " << err << std::endl;
	}
	catch (std::exception& err) {
		std::cout << "EXCEPTION: " << err.what() << std::endl;
	}

	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3u; i <= 4u; ++i)
	{
		// TODO: The following statement can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		try {
			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
		}
		catch (const char* err) {
			std::cout << "EXCEPTION: " << err << std::endl;
		}
		catch (std::exception& err) {
			std::cout << "EXCEPTION: " << err.what() << std::endl;
		}
	}

	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}




#include <iostream>
int main() {
	// lambda expressions
	auto hello = []() { return "Hello World"; };
	auto add4 = [](int i) { return i + 4; };
	auto sub4 = [](int i) { return i - 4; };

	// calls on the lambda expressions
	std::cout << hello() << std::endl; // Hello  World
	std::cout << add4(10) << std::endl; // 14
	std::cout << sub4(10) << std::endl; // 6
}

//[=] denotes capture by value. 
#include <iostream>
template<typename Func>
int add(int i, Func func) { return func(i); }

template<typename Func>
int sub(int i, Func func) { return func(i); }

int main() {
	int k = 4;
	std::cout << add(10, [=](int i) { return i + k; }) << std::endl; // 14
	std::cout << sub(10, [=](int i) { return i - k; }) << std::endl; // 6
}

//[&] denotes capture by reference.
 // Lambda Expressions
 // capture_by_reference.cpp

#include <iostream>

template<typename Func>
int add(int i, Func func) { return func(i); }

template<typename Func>
int sub(int i, Func func) { return func(i); }

int main() {
	int k = 4;
	std::cout << add(10, [&](int i) { return i + k++; }) << std::endl; // 14
	std::cout << "k = " << k << std::endl; // k = 5
	std::cout << sub(10, [&](int i) { return i - k++; }) << std::endl; // 5
	std::cout << "k = " << k << std::endl; // k = 6
}
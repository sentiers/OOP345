// Workshop 3 - Templates
//
// w3_lab.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/1/29
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "Set.h"
#include "Pair.h"
#include "Set.h"
#include "Pair.h"


int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// Process the parameter
	// The values in this file will be interpreted as numbers
	//     Sumation means mathematical addition of numbers.
	{
		sdds::Set<sdds::Pair<std::string, int>, 10> ticketSales;

		// get the data from the file
		{
			std::ifstream input(argv[1]);
			if (!input)
			{
				std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
				return 3;
			}
			do
			{
				char ticketType[64];
				int number;
				input >> ticketType >> number;
				if (input)
				{
					ticketSales += sdds::Pair<std::string, int> (ticketType, number);
				}
			} while (input);
			input.close();
		}

		std::cout << "Detail Ticket Sales\n"
		          << "--------------------------\n";
		for (size_t i = 0; i < ticketSales.size(); ++i)
			std::cout << ticketSales[i];
	}

	// done
	return 0;
}
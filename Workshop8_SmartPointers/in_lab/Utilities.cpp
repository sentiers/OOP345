// Workshop 8 - Smart Pointers
//
// Utilities.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/27
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (auto i = 0u; i < desc.size(); i++) {
			for (auto j = 0u; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* p = new Product(desc[i].desc, price[j].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
		}
		return priceList;
	}
}
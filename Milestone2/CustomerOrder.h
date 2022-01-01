// Milestone 2
//
// CustomerOrder.h
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/3/28
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SAFE_CUSTOMERORDER_H
#define SAFE_CUSTOMERORDER_H
#include "Station.h"
#include <vector>

struct Item {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name = "";
	std::string m_product = "";
	unsigned int m_cntItem = 0;
	Item** m_lstItem = nullptr;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string& str);
	CustomerOrder(const CustomerOrder& c);
	CustomerOrder& operator=(const CustomerOrder& c) = delete;
	CustomerOrder(CustomerOrder&& c) noexcept;
	CustomerOrder& operator=(CustomerOrder&& c) noexcept;
	virtual ~CustomerOrder();
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif
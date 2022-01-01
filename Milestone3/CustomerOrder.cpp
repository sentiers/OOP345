// Milestone 3
//
// CustomerOrder.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/4/5
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {};

CustomerOrder::CustomerOrder(const std::string& str) {

	Utilities u;
	size_t pos = 0;
	bool more = false;
	std::vector<Item*> vecItem;

	m_name = u.extractToken(str, pos, more);
	m_product = u.extractToken(str, pos, more);

	while (more) {
		vecItem.push_back(new Item(u.extractToken(str, pos, more)));
	}

	m_cntItem = vecItem.size();
	m_lstItem = new Item*[m_cntItem];

	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = std::move(vecItem[i]);
	}

	m_widthField = (m_widthField < u.getFieldWidth()) ? u.getFieldWidth() : m_widthField;
}

CustomerOrder::CustomerOrder(const CustomerOrder& c) {
	throw std::string("Error");
}

CustomerOrder::CustomerOrder(CustomerOrder && c) noexcept {
	*this = std::move(c);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder &&c) noexcept {
	if (this != &c) {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;

		m_name = c.m_name;
		m_product = c.m_product;
		m_cntItem = c.m_cntItem;
		m_lstItem = c.m_lstItem;

		c.m_name = "";
		c.m_product = "";
		c.m_cntItem = 0;
		c.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
	unsigned int size = 0;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled) {
			size++;
		}
	}
	return size >= m_cntItem;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool more = true;
	for (size_t i = 0; i < m_cntItem && more; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			more = m_lstItem[i]->m_isFilled;
		}
	}
	return more;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (station.getItemName() == m_lstItem[i]->m_itemName) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled ";
			}
			else if (station.getQuantity() == 0) {
				os << "Unable to fill";
			}
			os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] "
			<< std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - "
			<< (isItemFilled(m_lstItem[i]->m_itemName) ? "FILLED" : "MISSING") << std::endl;
	}
}
// Milestone 3
//
// LineManager.cpp
// Name: Hyunji Cho
// Seneca Student ID: 128065182
// Seneca email: hcho51@myseneca.ca
// Date of completion: 2020/4/5
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "LineManager.h"

LineManager::LineManager(const std::string& fileName, std::vector<Workstation*>& wStations, std::vector<CustomerOrder>& toFill) {

	Utilities u;
	bool more = true;
	std::string temp;
	std::string name;
	std::string nameNext;
	AssemblyLine = wStations;

	std::ifstream file(fileName);
	while (!file.eof()) {
		size_t pos = 0;
		more = true;
		std::getline(file, temp);
		name = u.extractToken(temp, pos, more);
		nameNext = more ? u.extractToken(temp, pos, more) : "";

		for (auto& i : AssemblyLine) {
			if (name == i->getItemName()) {
				for (auto j : AssemblyLine) {
					if (nameNext == j->getItemName()) {
						i->setNextStation(*j);
					}
				}
			}
		}
	}
	file.close();

	for (auto& i : toFill) {
		ToBeFilled.push_back(std::move(i));
		m_cntCustomerOrder++;
	}
}

bool LineManager::run(std::ostream& os) {
	static size_t cnt = 0;
	std::string temp = "";
	CustomerOrder c;

	for (auto& i : AssemblyLine) {
		if (i->getNextStation()) {
			temp += i->getNextStation()->getItemName();
		}
	}

	for (auto& i : AssemblyLine) {
		if (temp.find(i->getItemName()) == std::string::npos) {
			if (!ToBeFilled.empty()) {
				*i += std::move(ToBeFilled.front());
				ToBeFilled.pop_front();
			}
		}
	}

	os << "Line Manager Iteration: " << ++cnt << std::endl;
	for (auto& i : AssemblyLine) {
		i->runProcess(os);
	}

	for (auto& i : AssemblyLine) {
		i->moveOrder();
		if (i->getIfCompleted(c)) {
			Completed.push_back(std::move(c));
		}
	}

	return Completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (const auto& i : Completed) {
		i.display(os);
	}
}

void LineManager::displayStations() const {
	for (const auto& i : AssemblyLine) {
		i->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	std::vector<const Workstation*> stationSorted;
	std::string temp = "";

	for (auto& i : AssemblyLine) {
		if (i->getNextStation()) {
			temp += i->getNextStation()->getItemName();
		}
	}

	for (const auto& i : AssemblyLine) {
		if (temp.find(i->getItemName()) == std::string::npos) {
			stationSorted.push_back(i);
		}
	}

	for (size_t i = 0; stationSorted.back()->getNextStation(); i++) {
		stationSorted.push_back(stationSorted.back()->getNextStation());
	}

	for (const auto& i : stationSorted) {
		const_cast<Workstation*>(i)->display(std::cout);
	}
}
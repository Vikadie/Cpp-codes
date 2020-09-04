#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Company.h"

int main() {
	std::string name;
	int id;
	std::vector<Company> companyVec;

	while (std::cin >> name && name != "end") {
		std::cin >> id;

		companyVec.emplace_back(id, name);
	}
	std::string sortInd;
	std::cin >> sortInd;

	if (sortInd == "id") {
		std::sort(companyVec.begin(), companyVec.end(), [](const Company& a, const Company& b) {
			return a.getId() < b.getId();
			});
	}
	else {
		std::sort(companyVec.begin(), companyVec.end(), [](const Company& a, const Company& b) {
			return a.getName() < b.getName();
			});
	}

	for (Company& c: companyVec) {
		std::cout << c.toString() << std::endl;
	}

	return 0;
}
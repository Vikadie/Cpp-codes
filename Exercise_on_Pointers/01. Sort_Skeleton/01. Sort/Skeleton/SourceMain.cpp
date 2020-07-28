
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Company.h"

std::vector <Company> readFromInput() {
    std::vector <Company> companies;
    std::string input;

    while (getline(std::cin, input) && (input != "end")) {
        std::istringstream in(input);
        int companyId = 0;
        std::string companyName;

        in >> companyName >> companyId;
        companies.emplace_back(companyId, companyName);
    }

    return companies;
}

bool sortCompanyById(Company &a, Company &b) {
    return (a.getId() < b.getId());
}

bool sortCompanyByName(Company& a, Company& b) {
    return (a.getName() < b.getName());
}

int main()
{
    std::vector <Company> companies = readFromInput();

    std::string idOrName;
    std::cin >> idOrName;

    if (idOrName == "id") {
        std::sort(companies.begin(), companies.end(), sortCompanyById);
    }
    else if (idOrName == "name") {
        std::sort(companies.begin(), companies.end(), sortCompanyByName);
    }

    for (Company c : companies) {
        std::cout << c.toString() << std::endl;
    }

    return 0;
}
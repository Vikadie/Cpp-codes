#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include <istream>
#include <map>
#include <sstream>
#include <string>

#include "Company.h"
#include "ProfitCalculator.h"

using namespace std;

string getProfitReport(Company* fromInclusive, Company* toInclusive, map<int, ProfitCalculator> profitCalculatorsByCompany)
{
	// Company = name, id : revenue, cost
	// map<int, ProfitCalculator> = <id, tax percentage>
	ostringstream ss;

	while (fromInclusive <= toInclusive) {
		int profit = 0;
		for (auto element : profitCalculatorsByCompany) {
			if (element.first == fromInclusive->getId()) {
				profit = element.second.calculateProfit(*fromInclusive);
				break;
			}
		}

		ss << fromInclusive->getName() << " = " << profit << endl;
		fromInclusive++;
	}
	/*for (auto ids = profitCalculatorsByCompany.begin(); ids != profitCalculatorsByCompany.end(); ids++) {
		if (ids->first == fromInclusive->getId()) {
			while (ids->first != toInclusive->getId) {
				ss << << " = " << (ids->second).calculateProfit() << endl;
			}
		}
	}*/

	return ss.str();
}

#endif //PROFIT_REPORT_H


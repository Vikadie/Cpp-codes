#include <iostream>

using namespace std;
/*
Costs
Write a program that calculates monthly costs of a family. The family is from 3 persons (Mother, Father, Son)
CONSUMPTIONS and BENEFITS per all month
- Water
- Gas
- Needed money of Child (40 per month)
- Rent
- Electrical energy
- Mother Salary
- Father Salary
ALL the needed costs and salaries can NOT be NEGATIVE or ZERO!
For the calculates you have:
Daily electrical price per KW/h = 0.13;
Night electrical price per KW/h= 0.07;
Number of days = 30;
Water cost per cm3 = 1.65;
Gas cost per cm3 = 0.09;
You have to calculate TOTAL (per Month):
- Water costs
- Gas costs
- Electrical Energy costs
- All Costs
- Remaining Salary
- Money for 1 day


THE INPUT SHOULD BE:
1) Water consumption in cm3
2) Gas consumption in cm3
3) Daily energy in kw
4) Rent
5) Night energy in kw
6) Mother Salary
7) Father Salary

Example Input	
5
3
32
600
17
1500
1700	

Expected Output
Water : 8.25
Gas : 0.27
Energy : 5.35
All costs : 653.87
Remaining Salary : 2546.13
Money for one day : 84.871

Example Input
1000
1000
1000
1000
1000
1000
1000	

Expected Output
Water : 1650
Gas : 90
Energy : 200
All costs : 2980
Remaining Salary : -980
You should find new job !
Money for one day : -32.6667


*/
int main() {

	//serach for
	double costWater = 0, costGas = 0, costRent = 0, costElectricalEnergy, allCost = 0;

	//given
	double MotherSalary = 0, FatherSalary = 0;

	double const costNeededMoneyChild = 40;
	double const dailyElectrical = 0.13;
	double const nightElectrical = 0.07;

	int const numDays = 30;
	double const waterCostcm3 = 1.65;
	double gasCostcm3 = 0.09;

	// input
	int waterConsum;
	cin >> waterConsum;
	costWater = waterConsum * waterCostcm3;

	int gasConsum;
	cin >> gasConsum;
	costGas = gasConsum * gasCostcm3;

	int dailyElEnergy;
	cin >> dailyElEnergy;
	costElectricalEnergy = dailyElectrical * dailyElEnergy;

	cin >> costRent;

	int nightEnergy;
	cin >> nightEnergy;
	costElectricalEnergy += nightElectrical * nightEnergy;

	allCost = costElectricalEnergy + costRent + costGas + costWater + costNeededMoneyChild;

	cin >> MotherSalary;
	cin >> FatherSalary;

	cout << "Water : " << costWater << endl
		<< "Gas : " << costGas << endl
		<< "Energy : " << costElectricalEnergy << endl
		<< "All costs : " << allCost << endl
		<< "Remaining Salary : " << MotherSalary + FatherSalary - allCost << endl;
	if (MotherSalary + FatherSalary - allCost < 0)
		cout << "You should find new job !" << endl;
	cout << "Money for one day : " << (MotherSalary + FatherSalary - allCost) / numDays << endl;

	return 0;
}
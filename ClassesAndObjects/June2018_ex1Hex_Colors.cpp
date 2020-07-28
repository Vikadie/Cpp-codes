#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	string red1, green1, blue1;

	red1 = str.substr(1, 2);
	green1 = str.substr(3, 2);
	blue1 = str.substr(5, 2);
	
	string str1;
	cin >> str1;

	string red2, green2, blue2;

	red2 = str1.substr(1, 2);
	green2 = str1.substr(3, 2);
	blue2 = str1.substr(5, 2);
	
	int avgRed = (stoi(red1, 0, 16) + stoi(red2, 0, 16)) / 2;
	int avgGreen = (stoi(green1, 0, 16) + stoi(green2, 0, 16)) / 2;
	int avgBlue = (stoi(blue1, 0, 16) + stoi(blue2, 0, 16)) / 2;

	cout << "#";
	cout << setfill('0') << setw(2) << right << hex << avgRed;
	cout << setfill('0') << setw(2) << right << hex << avgGreen;
	cout << setfill('0') << setw(2) << right << hex << avgBlue;
	return 0;
}
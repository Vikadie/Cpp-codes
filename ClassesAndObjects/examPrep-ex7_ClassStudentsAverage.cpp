#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
	string name, surname;
	double average;
public:
	Student(string name, string surname, double average) :
		name(name),
		surname(surname),
		average(average)
	{
	}
	void print() {
		cout << name << " " << surname << " -> " << average << endl;
	}

	double getAver() {
		return(this->average);
	}

};

int main() {

	int entries;

	cin >> entries;

	vector <Student> all;
	while (entries--) {
		string name, surname;
		double average;

		cin >> name >> surname >> average;
		all.push_back(Student(name, surname, average));

	}
	double summ = 0;
	for (vector<Student>::iterator i = all.begin(); i < all.end(); i++) {
		i->print();
		summ += i->getAver();
	}
	cout << summ / all.size();

	return 0;
}
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*Write a program, make a Class Student. For given numbers the program should 
filter the students by MINIMUM VOTE, if the MINIMUM VOTE is 
greater or equal to the students vote, the program should give information. 
If the VOTE is lower than the filtered the program should NOT give information.*/

class Student {
private:
	string name, surname;
	int age;
	double vote;

public:
	Student() : 
		age(0),
		vote(0.0) {
	}
	Student(string name_, string surname_, int age_, double vote_) :
		name(name_),
		surname(surname_),
		age(age_),
		vote(vote_) {

	}

	double getVote() { 
		return(vote); 
	}

	//setters
	/*void setName(string name_) { name = name_; }
	void setName(string surname_) { surname = surname_; }
	void setAge(int age_) { age = age_; }
	void setVote(double vote_) { vote = vote_; }
	*/
	string getData(void) {
		ostringstream ostr;

		//ostr.precision(1);
		ostr << "Name -> " << name << " " << surname << endl
			<< "Age -> " << age << endl
			//<< fixed << "Vote ->" << vote;
			<< "Vote -> " << vote;

		return ostr.str()	;
	}
};


int main() {
	unsigned studentCount;

	cout << "How many students do you want to input?" << endl;
	cin >> studentCount;

	vector <Student> students;
	while (studentCount--) {
		string name, surname;
		int age;
		double vote;

		cout << "Enter name: " << endl;
		cin >> name;

		cout << "Enter surname: " << endl;
		cin >> surname;

		cout << "Enter age: " << endl;
		cin >> age;

		cout << "Enter vote (the vote can be with decimal point): " << endl;
		cin >> vote;

		students.push_back(Student(name, surname, age, vote));

	}

	double minVote;
	cout << "Which is the minimal vote that you would like to filter? " << endl;
	cin >> minVote;
	bool isThere = false;

	vector <Student>::iterator itStud = students.begin();
	for (itStud; itStud != students.end(); itStud++) {
		if (itStud->getVote() >= minVote) {
			// cout.precision(1);
			if (!isThere) {
				cout << "The students with MIN vote -> " << minVote << " are: " << endl;
				isThere = true;
			}
			cout << itStud->getData() << endl;

		}
		else
			if (itStud == students.end() - 1) {
				cout << "There are no student with MIN vote -> " << minVote << endl;
				// isThere = true;
			}
	}

	return 0;
}
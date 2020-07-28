#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* Twins:
Pepi and Mimi are twin sisters. All of their life they’ve been together. They live together, they work at the same place. 
Currently Pepi and Mimi are working at the famous big food store Kauf…brand. They are working simultaneously as cashiers on two adjacent 
cash registers.

Your job is to implement a program that described their work routine each minute for some provided period of time.
Then a set of customers is provided - each with a unique name and a number connected to him (representing how many minutes it will take to be processed).

For each minute of the provided working routine time you should print: 
? The name of the customer that is currently processed. 
? If no customers are left for any of the girl cash registers – you should print “Idle”

Important note: First you should print Pepi’s turn, then Mimi’s. 

Input
First read an integer (N) representing how many command lines will follow.
Then read N commands representing the customers.
Finally read an integer (T), which will indicate how many minutes of the twin’s work routine you should describe with your program.

Examples

Input  
2
Pepi Ivan 3
Mimi Ibrahim 2
3
Output
Pepi processing Ivan     //turn 1 for Pepi 
Mimi processing Ibrahim  //turn 1 for Mimi 
Pepi processing Ivan     //turn 2 for Pepi 
Mimi processing Ibrahim  //turn 2 for Mimi 
Pepi processing Ivan     //turn 3 for Pepi 
Mimi Idle                //turn 3 for Mimi

Input
4
Pepi Ivan 2
Mimi Ibrahim 3 
Pepi Toni 1
Pepi Minka 1
5
Output
Pepi processing Ivan
Mimi processing Ibrahim
Pepi processing Ivan 
Mimi processing Ibrahim
Pepi processing Toni
Mimi processing Ibrahim 
Pepi processing Minka
Mimi Idle
Pepi Idle 
Mimi Idle

Input
1
Mimi Manol 2
1
Output
Pepi Idle              //turn 1 for Pepi 
Mimi processing Manol  //turn 1
*/

int main() {
	int times = 0;
	vector <string> clientsPepi;
	vector <size_t> serviceTimePepi;
	vector <string> clientsMimi;
	vector <size_t> serviceTimeMimi;
	string name, client;
	size_t servicetime = 0;
	cin >> times;
	while (times--) {
		cin >> name >> client >> servicetime;
		if (name == "Pepi") {
				clientsPepi.push_back(client);
				serviceTimePepi.push_back(servicetime);
		}
		else {
			clientsMimi.push_back(client);
			serviceTimeMimi.push_back(servicetime);
			}
		}
	

	cin >> servicetime;

	unsigned turnP = 0, turnM = 0;
	for (size_t j = 0; j < servicetime; j++) {
		
		cout << "Pepi ";
		if (turnP >= clientsPepi.size()) {
			cout << "Idle" << endl;
		}
		else {
			if (serviceTimePepi[turnP] == 0) 
				turnP++;
			if (turnP >= clientsPepi.size()) {
				cout << "Idle" << endl;
			} else {
			cout << "processing " << clientsPepi[turnP] << endl;
			serviceTimePepi[turnP]--;
			}
		}

		cout << "Mimi ";
		if (turnM >= clientsMimi.size()) {
			cout << "Idle" << endl;
		}
		else {
			if (serviceTimeMimi[turnM] == 0)
				turnM++;
			if (turnM >= clientsMimi.size()) {
				cout << "Idle" << endl;
			}
			else {
				cout << "processing " << clientsMimi[turnM] << endl;
				serviceTimeMimi[turnM]--;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
/*
Algebra Helper
Little Ibrahim has some trouble with his math homework. He tries to learn some equation by heart. Help him out!
Ibrahim remembers the equations in his head by memorizing their result. He has good visual memory and utilizes it. 
He arranges the equations in his head in descending order by their result.
If two or more equations have the same result he keeps their order from the input. The first one remains first, second one – second, etc …
An equation will only be constructed from a 2 integers and an operating between the 2 integers.
NOTE: only the following 5 operations should be supported:
+ (sum)
- (subtraction)
* (multiplication)
/ (integer division)
% (integer modulo)
NOTE 2: there will be no brackets. Nothing fancy – just 2 integers and an operation between them.
Input
First a single integers (N) indicating how many equations will follow (each on a different line).
Next read (N) lines of equations. Each equation contains a number, after that an operations and then another number – always in that order.
*/

int main() {

	int N;
	cin >> N;

	map <int, vector <string>, greater<int> > results;
	while (N--) {
		int num1;
		cin >> num1;

		char oper;
		cin >> oper;
		
		int num2;
		cin >> num2;

		int result = 0;
		switch (oper)
		{
		case '+': result = num1 + num2; break;
		case '-': result = num1 - num2; break;
		case '*': result = num1 * num2; break;
		case '/': result = num1 / num2; break;
		case '%': result = num1 % num2; break;
		default:
			break;
		}
	
		stringstream in;
		in << num1 << " " << oper << " " << num2;
		string print = in.str();
		
		results[result].push_back(print);
	}

	//printing
	for (pair <int, vector<string> > element : results) {
		for (auto i : element.second)
			cout << i << endl;
	}

	return 0;
}
#include <iostream>

using namespace std;

class Time {
private:
	int hours, min, sec;
public:
	Time(int hours, int min, int sec) :
		hours(hours),
		min(min),
		sec(sec)
	{
	}
	void calculation() {
		cout << hours * 1 + min / 60 + sec / 3600 << endl
			<< hours * 60 + min + sec / 60 << endl
			<< hours * 3600 + min * 60 + sec;
	}
};

int main() {

	int hours, min, sec;

	cin >> hours >> min >> sec;
	Time answer(hours, min, sec);
	answer.calculation();

	return 0;
}
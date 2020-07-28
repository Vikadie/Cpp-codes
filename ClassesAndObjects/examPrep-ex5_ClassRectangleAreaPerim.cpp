#include <iostream>
#include <vector>

using namespace std;

class Rectangle {
private:
	int sideA, sideB;
public:
	Rectangle(int side1, int side2) : 
		sideA(side1), 
		sideB(side2) {
	}
	void Area() {
		int area = sideA * sideB;
		cout << area << endl;;
}
	void Perimeter() {
		int perimeter = 2 * (sideA + sideB);	
		cout << perimeter << endl;
	}
};

int main() {

	int side1;
	int side2;
	cin >> side1 >> side2;
	Rectangle answer(side1, side2);
	answer.Area();
	answer.Perimeter();

	return 0;
}
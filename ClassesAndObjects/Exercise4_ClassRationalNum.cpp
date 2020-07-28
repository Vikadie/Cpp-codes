#include <iostream>

using namespace std;
/*
Write a program, use a Class Rational Numbers. The class should have Numerator and Denominator, the variables should be INT.
Methods in the Class:
Setters, Getters, Print
NOTE – The set method of the Denominator for a given 0 the function should set 1 (you can find it in EXAMPLE 3)
Methods Extern:
Sum, Difference, Multiplication, Division
*/
class rationalNum {
private:
	int nom;
	int denom;
public:
	rationalNum(int nom_, int denom_):
		nom(nom_),
		denom(denom_){
	}

	rationalNum() : 
		nom(0), 
		denom(1) {
	}

	int getNom() { return(nom); }
	int getDenom() { return(denom); }
	void setNom(int nom_) { nom = nom_; }
	void setDenom(int denom_) { denom = (denom_ != 0) ? denom_ : 1; }

	void print() {
		cout << nom << "/" << denom << endl;
	}
};

rationalNum division(rationalNum first, rationalNum second) {
	int newNom = first.getNom() * second.getDenom();
	int newDenom = first.getDenom() * second.getNom();
	return rationalNum(newNom, newDenom);
}

rationalNum multiplication(rationalNum first, rationalNum second) {
	int newNom = first.getNom() * second.getNom();
	int newDenom = first.getDenom() * second.getDenom();
	return rationalNum(newNom, newDenom);
}

rationalNum difference(rationalNum first, rationalNum second) {
	int newNom = first.getNom()*second.getDenom() - second.getNom()*first.getDenom();
	int newDenom = first.getDenom() * second. getDenom();
	return rationalNum(newNom, newDenom);
}

rationalNum sum(rationalNum first, rationalNum second) {
	int newNom = first.getNom() * second.getDenom() + second.getNom() * first.getDenom();
	int newDenom = first.getDenom() * second.getDenom();
	return rationalNum(newNom, newDenom);
}

rationalNum setRational(string count) {
	int numerator, denominator;

	cout << "Enter " + count + " rational number numerator : ";
	cin >> numerator;

	cout << "Enter " + count + " rational number denominator : ";
	cin >> denominator;

	if (!denominator) {
		cout << "The denominator can't be 0, the denominator will be set to 1" << endl;
		denominator = 1;
	}

	return( rationalNum(numerator, denominator));
}

int main() {
	
	rationalNum first = setRational("first");
	rationalNum second = setRational("second");

	//sum(first, second).print();
	cout << "Sum  : "; sum(first, second).print();
	cout << "Difference : "; difference(first, second).print();
	cout << "Multiplication : "; multiplication(first, second).print();
	cout << "Division : "; division(first, second).print();
		

	return 0;
}
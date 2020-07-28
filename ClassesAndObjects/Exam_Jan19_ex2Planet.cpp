#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
Planet
Write a program, use Class or Struct that has the following params:
- Name
- Distance from Sun (in kilometers)
- Diameter
- Mass
- Print Function
- Function that calculate the number of seconds that the light needs to reach form the sun to the planet.
- For the following calculate you should know that the light has speed 299792 km/s
Make a vector that collects all the given planets.
Print all the information of the planets, print the calculate time.
Make a function that calculates the MINIMUM mass of all planets.
Make a function that calculates the MAXIMUM diameter.

The inputs are:
1) Name
2) Distance from Sun ( in kilometers )
3) Diameter
4) Mass
*/

class Planet {
private:
	string name;
	int distance_from_sun = 0;
	int diameter = 0;
	int mass = 0;
public:
	Planet(string name_, int distance_sun_, int d_, int m_): 
		name(name_), 
		distance_from_sun(distance_sun_),
		diameter(d_),
		mass(m_) {
	}
	int getMass() { return(mass); }
	int getDiameter() { return(diameter); }
	void print() {
		cout << name << " " << distance_from_sun << " " << diameter << " " << mass << endl;
	}
	int sunToPlanet()
	{
		int lightSpeed = 299792;
		return(distance_from_sun / lightSpeed);
	}
};

int maxDiameter(vector < Planet > vecPlanet) {
	int max = 0;
	for (unsigned it = 0; it < vecPlanet.size(); it++) {
		if (vecPlanet[it].getDiameter() > max)
			max = vecPlanet[it].getDiameter();
	}
	return(max);
}

int minMass(vector < Planet > vecPlanet) {
	int min = INT32_MAX;
	for (unsigned it = 0; it < vecPlanet.size(); it++) {
		if (vecPlanet[it].getMass() < min)
			min = vecPlanet[it].getMass();
	}
	return(min);
}
int main() {
	vector <Planet> planetVec;
	int numPlanet;
	cin >> numPlanet;

	while (numPlanet--) {
		string planetName;
		int distance, diameter, mass;
		cin >> planetName >> distance >> diameter >> mass;

		planetVec.push_back(Planet(planetName, distance, diameter, mass));
	}

	for (unsigned it = 0; it < planetVec.size(); it++) {
		planetVec[it].print();
		cout << planetVec[it].sunToPlanet() << endl;
	}
	cout << minMass(planetVec);
	cout << endl;
	cout << maxDiameter(planetVec);

	return 0;
}
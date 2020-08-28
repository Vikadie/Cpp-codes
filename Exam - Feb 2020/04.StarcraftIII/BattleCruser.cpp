#include "BattleCruser.h"
#include <iostream>

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId):
	TerranAirShip(type, health, damage, shipId)
{
}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	if ((_passedTurns + 1) % 5 == 0) {
		enemyFleet.back()->takeDamage(_damage * 5);
	} else
		enemyFleet.back()->takeDamage(_damage);
	if (enemyFleet.back()->getCurrHealth() <= 0) {
		std::cout << "BattleCruser with ID: " << _shipId << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
		enemyFleet.pop_back();
	}
}

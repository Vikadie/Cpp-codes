#include "Viking.h"
#include <iostream>

Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId): TerranAirShip(type, health, baseDamage, shipId)
{
}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	if (enemyFleet.back()->getAirShipType() == AirShipType::PHOENIX)
		enemyFleet.back()->takeDamage(_damage);
	enemyFleet.back()->takeDamage(_damage);
	if (enemyFleet.back()->getCurrHealth() <= 0) {
		std::cout << "Viking with ID: " << _shipId << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
		enemyFleet.pop_back();
	}
}

#include "Carrier.h"
#include <iostream>

Carrier::Carrier(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId):
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId),
	_activeInterceptors(InterceptorDefines::MAX_INTERCEPTORS)
{
}

void Carrier::takeDamage(const int damage)
{
	ProtossAirShip::takeDamage(damage);
	if (_currHealth < _maxHealth)
		_activeInterceptors = InterceptorDefines::DAMAGED_STATUS_INTERCEPTORS;
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	for (int i = 0; i < _activeInterceptors; i++) {
		enemyFleet.back()->takeDamage(_damage);
		if (enemyFleet.back()->getCurrHealth() <= 0) {
			std::cout << "Carrier with ID: " << _shipId << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
			enemyFleet.pop_back();
			if (enemyFleet.empty())
				break;
		}
	}
}

#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId): 
	AirShip(type, health, damage, shipId),
	_currShield(maxShield),
	_maxShield(maxShield),
	_shieldRegenerateRate(shieldRegenerateRate)
{
}

void ProtossAirShip::takeDamage(const int damage)
{
	_currShield -= damage;
	if (_currShield < 0) {
		_currHealth += _currShield;
		_currShield = 0;
	}
		
}

void ProtossAirShip::finishTurn()
{
	if (_airShipType == AirShipType::PHOENIX) {
		_currShield += 20;
	}
	else {
		_currShield += 40;
	}
	if (_currShield > _maxShield)
		_currShield = _maxShield;
}

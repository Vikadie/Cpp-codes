#include "DesertEagle.h"
#include <iostream>

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo): Pistol(damagePerRound, clipSize, remainingAmmo) { }

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData)
{
	if (_currClipBullets > 0) {
		if (enemyPlayerData.armor <= 0) {
			enemyPlayerData.health -= _damagePerRound;
		}
		else {
			int armorDamage = _damagePerRound / 4;
			int healthDamage = 3 * _damagePerRound / 4;
			if (enemyPlayerData.armor < armorDamage) {
				armorDamage -= enemyPlayerData.armor;
				enemyPlayerData.armor = 0;
			}
			else {
				enemyPlayerData.armor -= armorDamage;
				armorDamage = 0;
			}
			enemyPlayerData.health -= (healthDamage + armorDamage);
		}
		_currClipBullets--;
		std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;
	}
	else {
		reload();
	}

	if (enemyPlayerData.health > 0)
		return false;
	return true;
}

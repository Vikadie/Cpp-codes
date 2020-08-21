#include "Glock.h"

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo): Pistol(damagePerRound, clipSize, remainingAmmo) { }

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
	if (_currClipBullets > 0) {
		int numShots = 3;
		int shotsCount = 0;
		if (_currClipBullets < 3)
			numShots = _currClipBullets;
		while (numShots > 0 && enemyPlayerData.health > 0) {
			if (enemyPlayerData.armor <= 0) {
				enemyPlayerData.health -= _damagePerRound;
			}
			else {
				int armorDamage = _damagePerRound / 2;
				int healthDamage = _damagePerRound / 2;
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
			numShots--;
			shotsCount++;
			std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;
		}
		if (shotsCount < 3 && enemyPlayerData.health > 0)
			reload();
	}
	else {
		reload();
	}

	if (enemyPlayerData.health > 0)
		return false;
	return true;
}

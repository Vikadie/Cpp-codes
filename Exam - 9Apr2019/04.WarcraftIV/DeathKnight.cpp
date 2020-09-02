#include "DeathKnight.h"
#include <iostream>

DeathKnight::DeathKnight(const std::string& name, const int maxMana, const int baseManaRegenRate) : Hero(name, maxMana, baseManaRegenRate) { }

void DeathKnight::castSpell(const SpellType spell)
{
	std::cout << this->_name;
	if (this->_currMana >= this->_spells[spell].manaCost) {
		std::cout << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana";
		this->_currMana -= this->_spells[spell].manaCost;
		if (spell == SpellType::ULTIMATE)
			std::cout << std::endl << 
			this->_name << " casted " << this->_spells[SpellType::BASIC].name << " for 0 mana";
	}
	else {
		std::cout << " - not enough mana to cast " << this->_spells[spell].name;
	}
	std::cout << std::endl;
}

void DeathKnight::regenerateMana()
{
	_currMana += _manaRegenRate;
	if (_currMana > _maxMana)
		_currMana = _maxMana;
}

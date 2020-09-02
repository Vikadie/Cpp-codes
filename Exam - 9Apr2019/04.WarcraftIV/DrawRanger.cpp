#include "DrawRanger.h"
#include <iostream>

DrawRanger::DrawRanger(const std::string& name, const int maxMana, const int baseManaRegenRate): Hero(name, maxMana, baseManaRegenRate) { }

void DrawRanger::castSpell(const SpellType spell)
{
	std::cout << this->_name;
	if (this->_currMana >= this->_spells[spell].manaCost) {
		std::cout << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana";
		this->_currMana -= this->_spells[spell].manaCost;
		if (spell == SpellType::BASIC)
			std::cout << std::endl <<
			this->_name << " casted " << this->_spells[SpellType::BASIC].name << " for 0 mana";
	}
	else {
		std::cout << " - not enough mana to cast " << this->_spells[spell].name;
	}
	std::cout << std::endl;
}

void DrawRanger::regenerateMana()
{
	_currMana += _manaRegenRate;
	if (_currMana > _maxMana)
		_currMana = _maxMana;
}

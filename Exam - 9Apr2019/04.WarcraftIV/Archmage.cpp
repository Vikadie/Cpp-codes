#include "Archmage.h"
#include <iostream>

Archmage::Archmage(const std::string& name, const int maxMana, const int baseManaRegenRate, const int manaRegenModifier) : 
	Hero(name, maxMana, baseManaRegenRate), 
	_manaRegenModifier(manaRegenModifier) 
{ }

void Archmage::castSpell(const SpellType spell)
{
	std::cout << this->_name;
	if (this->_currMana >= this->_spells[spell].manaCost) {
		std::cout << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana";
		this->_currMana -= this->_spells[spell].manaCost;
		if (spell == SpellType::ULTIMATE)
			regenerateMana();
	}
	else {
		std::cout << " - not enough mana to cast " << this->_spells[spell].name;
	}
	std::cout << std::endl;
}

void Archmage::regenerateMana()
{
	_currMana += _manaRegenRate * _manaRegenModifier;
	if (_currMana > _maxMana)
		_currMana = _maxMana;
}

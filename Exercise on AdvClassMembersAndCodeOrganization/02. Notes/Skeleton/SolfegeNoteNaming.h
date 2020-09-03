#pragma once
#ifndef SOLFEGE_NOTE_NAMING_H
#define SOLFEGE_NOTE_NAMING_H

#include "NoteName.h"


class SolfegeNoteNaming {
public:
	SolfegeNoteNaming() {}

	NoteName operator()(const std::string& textNote) const {
		if (textNote == "Do")
			return NoteName('C');
		else if (textNote == "Re")
			return NoteName('D');
		else if (textNote == "Mi")
			return NoteName('E');
		else if (textNote == "Fa")
			return NoteName('F');
		else if (textNote == "Sol")
			return NoteName('G');
		else if (textNote == "La")
			return NoteName('A');
		else if (textNote == "Si")
			return NoteName('B');
		else
			return NoteName('?');
	}
};

#endif // !SOLFEGE_NOTE_NAMING_H

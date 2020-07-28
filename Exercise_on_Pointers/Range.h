#pragma once
class Range
{
private:
	int from = 0;
	int to = 0;
public:
	Range(int from_, int to_) : 
		from(from_), 
		to(to_) {
	}

	int getFrom() {
		return from;
	}

	int getTo() {
		return to;
	}
};


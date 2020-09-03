#pragma once
#ifndef MAX_H
#define MAX_H

class VectorMax {
	std::vector<int> mSet;
	int maxValue;
public:
	VectorMax(): maxValue(INT_MIN) {}

	friend bool operator< (const VectorMax& a, const VectorMax& b);

	friend VectorMax& operator>>(const std::vector<int>& arr, VectorMax& m);

	friend std::ostream& operator<<(std::ostream& out, VectorMax& m);
};

VectorMax& operator>>(const std::vector<int>& arr, VectorMax& m) {
	
	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i] > m.maxValue)
			m.maxValue = arr[i];
		m.mSet.push_back(arr[i]);
	}
	return m;
}

bool operator< (const VectorMax& a, const VectorMax& b) {
	return a.maxValue < b.maxValue;
}

std::ostream& operator<<(std::ostream& out, VectorMax& m) {
	auto itr = m.mSet.begin();
	for (itr; itr != m.mSet.end(); itr++)
		out << *itr << " ";
	
	return out;
}


#endif // !MAX_H

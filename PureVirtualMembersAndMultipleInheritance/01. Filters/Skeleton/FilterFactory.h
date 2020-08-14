#pragma once
#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

class FilterFactory: public Filter {
	
	char charBegin;
	char charEnd;
public:
	FilterFactory(){}

	FilterFactory(char first, char last): 
		charBegin(first),
		charEnd(last)
	{}
	
	virtual bool shouldFilterOut(char symbol) const {	
		return (charBegin <= symbol && symbol <= charEnd);
	}

	FilterFactory* buildFilter (std::string filterDefinition) const {
		size_t len = filterDefinition.length();
		FilterFactory* var = new FilterFactory(filterDefinition[0], filterDefinition[len - 1]);
		return var;
	}

	virtual ~FilterFactory(){}
};

#endif // !FILTER_FACTORY_H

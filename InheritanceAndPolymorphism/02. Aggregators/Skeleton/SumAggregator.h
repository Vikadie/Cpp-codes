#pragma once
#ifndef SUM_AGGREGATOR_H
#define SUM_AGGREGATOR_H

class SumAggregator : public StreamAggregator {
public:
	SumAggregator(std::istringstream& stream) : StreamAggregator(stream) {
		this->aggregationResult = 0;
	}

	virtual void aggregate(int next) override {
		aggregationResult += next;		
	}

	~SumAggregator(){}
};
#endif // !SUM_AGGREGATOR_H

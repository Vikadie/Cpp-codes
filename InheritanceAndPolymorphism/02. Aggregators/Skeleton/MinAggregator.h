#pragma once
#ifndef MIN_AGGREGATOR_H
#define MIN_AGGREGATOR_H

class MinAggregator : public StreamAggregator {
	int min;
public:
	MinAggregator(std::istringstream& stream) : StreamAggregator(stream), min(INT_MAX) {}

	virtual void aggregate(int next) override {
		if (next < min) {
			aggregationResult = next;
			min = aggregationResult;
		}
	}

	~MinAggregator(){}
};
#endif // !MIN_AGGREGATOR_H

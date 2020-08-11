#pragma once
#ifndef AVERAGE_AGGREGATOR
#define AVERAGE_AGGREGATOR

class AverageAggregator : public StreamAggregator {
	int ssum;
public:
	AverageAggregator(std::istringstream& stream) : StreamAggregator(stream), ssum(0) {
		aggregationResult = 0;
	}

	virtual void aggregate(int next) override {
		ssum += next;
		StreamAggregator::aggregate(next);
		aggregationResult = jobDone(ssum);
	}

	int jobDone(int ssum) {
		int result = (int)(ssum / (this->getNumAggregated()));
		return result;
	}

	~AverageAggregator(){}
};
#endif // !AVERAGE_AGGREGATOR

#pragma once

#include "metaldetectorobserver.h"

#include <deque>

class MetalStatistics : public metaldetectorobserver {
public:
	explicit MetalStatistics(int maxHistorySize = 5);
	void onMetalDetected(double height) override;
	void onNoMetalDetected() override;
	void reset();

	int getMetalCount() const { return metalCount; }
	double getLastMetalHeight() const { return lastMetalHeight; }
	double getAverageMetalHeight() const;

	int getHistorySize() const { return static_cast<int>(heightHistory.size()); }
	double getHistoryHeight(int index) const;
	double getHistoryAverage() const;

private:
	int metalCount = 0;
	double lastMetalHeight = 0.0;
	std::deque<double> heightHistory;
	const int maxHistorySize;
};

#include "MetalStatistics.h"
#include <algorithm>

MetalStatistics::MetalStatistics(int maxHistorySize)
	: maxHistorySize{ maxHistorySize }
{
}

void MetalStatistics::onMetalDetected(double height)
{
	metalCount++;
	lastMetalHeight = height;
	heightHistory.push_front(height);

	if (heightHistory.size() > maxHistorySize) {
		heightHistory.pop_back();
	}
}


void MetalStatistics::reset()
{
	metalCount = 0;
	lastMetalHeight = 0.0;
	heightHistory.clear();
}

double MetalStatistics::getAverageMetalHeight() const
{
	if (metalCount == 0) {
		return 0.0;
	}

	double totalHeight = lastMetalHeight;
	for (double height : heightHistory) {
		totalHeight += height;
	}

	return totalHeight / (getHistorySize() + 1);
}

double MetalStatistics::getHistoryHeight(int index) const
{
	if (index < 0 || index >= getHistorySize()) {
		return 0.0;
	}

	return heightHistory[index];
}

double MetalStatistics::getHistoryAverage() const
{
	if (getHistorySize() == 0) {
		return 0.0;
	}

	double totalHeight = 0.0;
	for (double height : heightHistory) {
		totalHeight += height;
	}

	return totalHeight / getHistorySize();
}
void MetalStatistics::onNoMetalDetected() {

}
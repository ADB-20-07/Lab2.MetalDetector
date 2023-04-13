#include "metaldetector.h"
#include "metalstatistics.h"
#include "metaldetectorobserver.h"
#include <iostream>
#include <vector>
#include "Lab2.ind.h"

int main()
{
	MetalDetector detector;
	MetalStatistics statistics;      


	detector.attach(&statistics);

	// Симулируем проход 5 человек
	for (int i = 0; i < 5; i++) {
		double height = static_cast<double>(i + 1) * 0.5;
		detector.notifyMetalDetected(height);
	}

	std::cout << "Metal count: " << statistics.getMetalCount() << std::endl;
	std::cout << "Last metal height: " << statistics.getLastMetalHeight() << std::endl;
	std::cout <<  "Average metal height: " << statistics.getAverageMetalHeight() << std::endl;

	std::cout << "History size: " << statistics.getHistorySize() << std::endl;
	for (int i = 0; i < statistics.getHistorySize(); i++) {
		std::cout << "History height " << i << ": " << statistics.getHistoryHeight(i) << std::endl;
	}

	std::cout << "History average: " << statistics.getHistoryAverage() << std::endl;

	return 0;
}


#include "MetalDetector.h"

void MetalDetector::attach(metaldetectorobserver* observer) {
	observers_.push_back(observer);
}

void MetalDetector::detach(metaldetectorobserver* observer) {
	auto it = std::find(observers_.begin(), observers_.end(), observer);
	if (it != observers_.end()) {
		observers_.erase(it);
	}
}

void MetalDetector::notifyMetalDetected(double height)
{
	isMetalDetected_ = true;
	height_ = height;
	for (auto observer : observers_) 
	{
		observer->onMetalDetected(height);
	}
}

void MetalDetector::notifyNoMetalDetected() 
{
	isMetalDetected_ = false;
	for (auto observer : observers_) 
	{
		observer->onNoMetalDetected();
	}
}

double MetalDetector::getheight() const {
	return height_;
}

bool MetalDetector::isMetalDetected() const {
	return isMetalDetected_;
}
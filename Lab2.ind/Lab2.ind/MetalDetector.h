#pragma once
#include <vector>
#include "metaldetectorobserver.h"
class MetalDetector
{
public:
	//add observer
	void attach(metaldetectorobserver* observer);

	//remove observer
	void detach(metaldetectorobserver* observer);

	//update observer about nalichie and hight
	void notifyMetalDetected(double hight);

	//update observer notify without metal
	void notifyNoMetalDetected(); 

	double getheight() const;

	bool isMetalDetected() const;
private:
	std::vector<metaldetectorobserver*> observers_;
	bool isMetalDetected_ = false;
	double height_ = 0.0;

};


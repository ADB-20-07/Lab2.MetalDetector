#pragma once
class metaldetectorobserver
{
public:
	virtual void onMetalDetected(double height) = 0;
	virtual void onNoMetalDetected() = 0;
};


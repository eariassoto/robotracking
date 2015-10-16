#pragma once
#include "Leap.h"

using namespace Leap;

class LeapHost{

public:
	LeapHost(int, int);
	~LeapHost();

	bool update();
	int  getX();
	int  getY();
	bool  getHandPressed();

private:

	Controller *controller;
	Frame      lastFrame;
	int        x, y, tamX, tamY;
	bool       handPressed;
};
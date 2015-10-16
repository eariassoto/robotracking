#include "LeapHost.h"

LeapHost::LeapHost(int _x, int _y)
{
	tamX = _x;
	tamY = _y;
	controller = new Controller();
	controller->enableGesture(Gesture::TYPE_SCREEN_TAP);
	handPressed = false;
	x = 0;
	y = 0;
}

bool LeapHost::update()
{
	bool leapClic = false;
	Frame frame = controller->frame();

	if (frame != lastFrame)
	{
		InteractionBox iBox = frame.interactionBox();
		HandList hands = frame.hands();

		if (hands.count() == 1){
			Hand hand = hands[0];
			if (hand.isValid()){

				Vector leapPoint = hand.stabilizedPalmPosition();
				Vector normalizedPoint = iBox.normalizePoint(leapPoint, false);

				
				x = normalizedPoint.x * tamX;
				y = (1 - normalizedPoint.y) * tamY;
				printf("x, y %d %d", x, y);

				float strength = hand.grabStrength();

				if (!handPressed && strength > .9){
					handPressed = true;
				}
				else{
					if (handPressed && strength < .7){
						handPressed = false;
						leapClic = true;
					}
				}
			}
		}

		lastFrame = frame;
	}
	return leapClic;
}

int LeapHost::getX()
{
	return x;
}

int LeapHost::getY()
{
	return y;
}

bool LeapHost::getHandPressed()
{
	return handPressed;
}

LeapHost::~LeapHost()
{
	delete controller;
}
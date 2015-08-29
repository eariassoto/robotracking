#include "ofApp.h"
#include "espacioTeclado.h"

ofApp::ofApp(int x, int y)
{
	tamX = x;
	tamY = y;
	inputMode = true;
}

void ofApp::setup()
{
	ofSetWindowTitle("RoboTracking");
	ofBackground(255, 255, 255);

	controller = new Leap::Controller();
	controller->enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);

	mPrincipal = new menuPrincipal(inputMode);
	espacioActivo = mPrincipal;
	mPrincipal->setup();

	handPressed = false;
	
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	espacioBase* a = espacioActivo;

	bool leapClic = false;
	int mX, mY, lX, lY;
	if (!inputMode){
		mX = mY = -1;

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

					leapX = lX = normalizedPoint.x * tamX;
					leapY = lY = (1 - normalizedPoint.y) * tamY;

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

	}
	else{
		mX = mouseX;
		mY = mouseY;
		lX = lY = -1;
		
	}
	
	espacioActivo = espacioActivo->update(mX, mY, lX, lY, leapClic);
	if (espacioActivo == 0)
	{
		delete controller;
		ofExit();
	}
	else{
		if (espacioActivo == mPrincipal){
			inputMode = mPrincipal->visionMode;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	espacioActivo->draw();

	ofFill();
	ofEnableAlphaBlending();
	
	if (inputMode){
		ofSetColor(0, 0, 200, 127);
		ofCircle(mouseX, mouseY, 25);
	}
	else{
		if (handPressed){
			ofSetColor(0, 200, 0, 127);
		}
		else{
			ofSetColor(0, 0, 200, 127);
		}
		ofCircle(leapX, leapY, 25);
	}
	ofNoFill();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (key == 't')
	{
		mPrincipal->visionMode = inputMode = !inputMode;
		mPrincipal->btnInput->toggle();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}

ofApp::~ofApp(){
	delete mPrincipal;
}

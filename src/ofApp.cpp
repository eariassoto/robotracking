#include "ofApp.h"
#include <cmath>
#include "espacioTeclado.h"

ofApp::ofApp(Modo m, int x, int y, HWND _hwndWindow)
{
	tamX = x;
	tamY = y;
	modo = m;
	hwndWindow = _hwndWindow;
	host = EyeXHost::instance(_hwndWindow);
	leapHost = new LeapHost(x, y);
	ultimoX = host->x;
	ultimoY = host->y;
}

void ofApp::setup()
{
	ofSetWindowTitle("RoboTracking");
	ofBackground(255, 255, 255);

	mPrincipal = new menuPrincipal();
	espacioActivo = mPrincipal;
	mPrincipal->setup();

}

//--------------------------------------------------------------
void ofApp::update()
{
	espacioBase* a = espacioActivo;
	int inputX, inputY;

	switch (modo)
	{
	case Modo::Tobii:
		inputX = host->x;
		inputY = host->y;
		espacioActivo = espacioActivo->update(inputX, inputY);
		break;
	case Modo::Mouse:
		inputX = mouseX;
		inputY = mouseY;
		espacioActivo = espacioActivo->update(inputX, inputY);
		break;
	case Modo::Leap:
		bool leapClic = false;
		leapClic = leapHost->update();
		inputX = leapHost->getX();
		inputY = leapHost->getY();
		espacioActivo = espacioActivo->update(inputX, inputY, leapClic);
		break;
	}
	
	if (espacioActivo == 0)
	{
		delete leapHost;
		ofExit();
	}
	else{
		if (espacioActivo == mPrincipal){
			//inputMode = mPrincipal->visionMode;
		}
	}
}


double ofApp::circleDistance(double dX0, double dY0, double dX1, double dY1)
{
	return sqrt((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0));
}
//--------------------------------------------------------------
void ofApp::draw()
{
	espacioActivo->draw();

	ofFill();
	ofEnableAlphaBlending();
	
	switch (modo)
	{
	case ofApp::Modo::Tobii:
		if (circleDistance(ultimoX, ultimoY, host->x, host->y) > radioMirada)
		{
			ultimoX = host->x;
			ultimoY = host->y;
		}

		ofSetColor(0, 0, 200, 127);
		ofCircle(ultimoX, ultimoY, radioMirada);
		break;
	case ofApp::Modo::Mouse:
		ofSetColor(0, 0, 200, 127);
		ofCircle(mouseX, mouseY, radioMirada);
		break;
	case ofApp::Modo::Leap:
		if (leapHost->getHandPressed()){
			ofSetColor(0, 200, 0, 127);
		}
		else{
			ofSetColor(0, 0, 200, 127);
		}
		ofCircle(leapHost->getX(), leapHost->getY(), radioMirada);
		break;
	default:
		break;
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
		//mPrincipal->visionMode = inputMode = !inputMode;
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

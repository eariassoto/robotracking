#include "ofMain.h"
#include "ofApp.h"
#include "eyex/EyeX.h"
#pragma comment (lib, "Tobii.EyeX.Client.lib")

int main(){

	ofSetWorkingDirectoryToDefault();	

	int x = 1280;
	int y = 720;
	ofSetupOpenGL(x, y, OF_WINDOW);
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	HWND hwndWindow = ofGetWin32Window();
	ofRunApp(new ofApp(ofApp::Modo::Mouse, x, y, hwndWindow));
	

}

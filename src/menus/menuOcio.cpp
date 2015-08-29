#include "menuOcio.h"


menuOcio::menuOcio(espacioBase* mPadre) : menuBase("menus/menuOcio.xml", mPadre){
	
};

void menuOcio::setup(){
	menuBase::setup();
	espCamara = new espacioCamara(this);
	espCamara->setup();
}

menuOcio::~menuOcio(){
	delete espCamara;
}

espacioBase* menuOcio::eventos(int index){
	espacioBase* r = this;

	switch (index){
	case -1:
		r = espacioPadre;
		break;
	case 2:
		r = espCamara;
		break;
	default:
		break;
	}

	return r;
}
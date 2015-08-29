#include "menuComunicacion.h"

void menuComunicacion::setup(){
	menuBase::setup();
	espTeclado = new espacioTeclado("interfaz1.xml", this);
	espPictograma = new espacioPictograma(this);
	espSiNo = new espacioSiNo(this);
	espTeclado->setup(); 
	espPictograma->setup();
	espSiNo->setup();
}

espacioBase* menuComunicacion::eventos(int index){
	espacioBase* r = this;

	switch (index){
	case 0:
		r = espSiNo;
		break;
	case 1:
		r = espPictograma;
		break;
	case 2:
		r = espTeclado;
		break;
	case -1:
		r = espacioPadre;
		break;
	default:
		break;
	}

	return r;
}

menuComunicacion::~menuComunicacion(){
	delete espSiNo;
	delete espTeclado;
	delete espPictograma;
}
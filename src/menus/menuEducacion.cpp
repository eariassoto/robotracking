#include "menuEducacion.h"

espacioBase* menuEducacion::eventos(int index){
	espacioBase* r = this;

	switch (index){
	case -1:
		r = espacioPadre;
		break;
	case 0:
		r = tarjetas;
		break;
	default:
		break;
	}

	return r;
}

void menuEducacion::setup(){
	menuBase::setup();
	tarjetas = new espacioTarjetas(this);
	tarjetas->setup();
}

menuEducacion::~menuEducacion(){
	delete tarjetas;
}

#include "menuCotidiana.h"

espacioBase* menuCotidiana::eventos(int index){
	espacioBase* r = this;

	switch (index){
	case -1:
		r = espacioPadre;
		break;
	default:
		break;
	}

	return r;
}
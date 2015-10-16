#include "botonToggle.h"

botonToggle::botonToggle(string r1, string r2, float esc, string t1, string t2, int tamFuente, ofColor c, int x, int y, int w_, int h_) : botonImagen(r1, esc, t1, tamFuente, c, x, y, w_, h_)
{
	toggleState = false;
	ruta1 = r1;
	ruta2 = r2;
	texto1 = t1;
	texto2 = t2;
	w = w_;
	h = h_;
	escala = esc;
}

botonToggle::botonToggle(string r1, string r2, float esc, string t1, string t2, int tamFuente, ofColor c) : botonImagen(r1, esc, t1, tamFuente, c)
{
	toggleState = false;
	ruta1 = r1;
	ruta2 = r2;
	texto1 = t1;
	texto2 = t2;
}

bool botonToggle::update(bool res)
{
	if (res){
		if (toggleState){
			imagen.loadImage(ruta1);
			imagen.resize(w*escala, h*escala);
			texto = texto1;
		}
		else{
			imagen.loadImage(ruta2);
			imagen.resize(w*escala, h*escala);
			texto = texto2;
		}
		toggleState = !toggleState;
	}
	return res;
}

bool botonToggle::update(float x, float y){
	bool res = botonImagen::update(x, y);
	update(res);
	return res;
}

bool botonToggle::update(float x, float y, bool c){
	bool res = botonImagen::update(x, y, c);
	update(res);
	return res;
}

void botonToggle::toggle(){
	if (toggleState){
		imagen.loadImage(ruta1);
		imagen.resize(w*escala, h*escala);
		texto = texto1;
	}
	else{
		imagen.loadImage(ruta2);
		imagen.resize(w*escala, h*escala);
		texto = texto2;
	}
	toggleState = !toggleState;
}

bool botonToggle::state(){ 
	return toggleState;
}
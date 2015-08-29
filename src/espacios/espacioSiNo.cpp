#include "espacioSiNo.h"

espacioSiNo::espacioSiNo(espacioBase* espPadre) :espacioBase(espPadre){
	fuenteSiNo.loadFont("opensansfont.ttf", 180);
}

void espacioSiNo::setup(){
	btnAtras = new botonImagen("img/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);
}

espacioSiNo::~espacioSiNo(){
	delete btnAtras;
}

espacioBase* espacioSiNo::update(float x, float y, float xL, float yL, bool clic)
{
	espacioBase* r = this;
	
	if (btnAtras->update(x, y, xL, yL, clic))
	{
		r = espacioPadre;
	}

	return r;
}

void espacioSiNo::draw()
{
	btnAtras->draw();

	ofSetColor(240, 240, 240);
	ofRect(0, 0, 1030, 360);

	ofSetColor(220, 220, 220);
	ofRect(0, 360, 1030, 360);

	ofSetColor(35, 232, 51);
	ofRectangle cajaTexto = fuenteSiNo.getStringBoundingBox("Si", 0, 0);
	float posx = (1030 - cajaTexto.width) / 2;
	float posy = (360 - cajaTexto.height) / 2 + cajaTexto.height;
	fuenteSiNo.drawString("Si", posx, posy);

	ofSetColor(255, 33, 23);
	cajaTexto = fuenteSiNo.getStringBoundingBox("No", 0, 0);
	posx = (1030 - cajaTexto.width) / 2;
	posy = (360 - cajaTexto.height) / 2 + cajaTexto.height + 360;
	fuenteSiNo.drawString("No", posx, posy);
}


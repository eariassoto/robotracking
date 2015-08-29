#include "cajaTexto.h"

cajaTexto::cajaTexto(int tamFuente, ofColor c, int x, int y, int w, int h) : componenteBase(x, y, w, h)
{
	texto = "";
	fuente.loadFont("Sansation_Regular.ttf", tamFuente);
	colorFuente = c;

};

string cajaTexto::getTexto(){
	return texto;
}

void cajaTexto::draw()
{

	ofSetColor(150, 150, 150);
	ofRect(x, y, width, height);

	ofSetColor(colorFuente);

	ofRectangle cajaTexto = fuente.getStringBoundingBox(texto, 0, 0);
	float widthTexto = cajaTexto.width;
	float heightTexto = cajaTexto.height;

	float sobranteX = (width - widthTexto) / 2;
	float sobranteY = (height - heightTexto) / 2.0f + (heightTexto);

	fuente.drawString(texto, x + sobranteX, y + sobranteY);
}

void cajaTexto::appendTexto(string t)
{
	texto += t;
}

void cajaTexto::borrarCaracter()
{
	if (texto != "")
	{
		texto = texto.substr(0, texto.size() - 1);
	}
}

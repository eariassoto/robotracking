#include "cajaTexto.h"

cajaTexto::cajaTexto(int tamFuente, ofColor c, int x, int y, int w, int h) : componenteBase(x, y, w, h)
{
	texto = "";
	fuente.loadFont("Sansation_Regular.ttf", tamFuente);
	fuenteInicial = tamFuente;
	colorFuente = c;
	margenMaxTexto = width*0.85;
	margenMinTexto = width*0.6;
	razonCambioFuente = 2;
	alfa = -1;

	color.set(150, 150, 150);
};

cajaTexto::cajaTexto(int tamFuente, ofColor c, int x, int y, int w, int h, int a) : componenteBase(x, y, w, h)
{
	texto = "";
	fuente.loadFont("Sansation_Regular.ttf", tamFuente);
	fuenteInicial = tamFuente;
	margenMaxTexto = width*0.85;
	margenMinTexto = width*0.6;
	razonCambioFuente = 2;
	alfa = a;

	colorFuente.set(c.r, c.g, c.b, alfa);
	color.set(150, 150, 150, alfa);
};

string cajaTexto::getTexto(){
	return texto;
}

void cajaTexto::limpiar()
{
	texto = "";
	fuente.loadFont("Sansation_Regular.ttf", fuenteInicial);
}

void cajaTexto::draw()
{

	ofSetColor(color);
	if (alfa > 0)
	{
		ofEnableAlphaBlending();
	}
	ofFill();
	ofRect(x, y, width, height);

	ofSetColor(colorFuente);

	ofRectangle cajaTexto = fuente.getStringBoundingBox(texto, 0, 0);
	float widthTexto = cajaTexto.width;
	float heightTexto = cajaTexto.height;

	float sobranteX = (width - widthTexto) / 2;
	float sobranteY = (height - heightTexto) / 2.0f + (heightTexto);

	fuente.drawString(texto, x + sobranteX, y + sobranteY);

	if (alfa > 0)
	{
		ofDisableAlphaBlending();
	}
}

void cajaTexto::appendTexto(string t)
{
	texto += t;
	int w = fuente.getStringBoundingBox(texto, 0, 0).width;
	while (w > margenMaxTexto)
	{
		fuente.loadFont("Sansation_Regular.ttf", fuente.getSize() - razonCambioFuente);
		w = fuente.getStringBoundingBox(texto, 0, 0).width;
	}
	
}

void cajaTexto::borrarCaracter()
{
	if (texto != "")
	{
		texto = texto.substr(0, texto.size() - 1);

		int w = fuente.getStringBoundingBox(texto, 0, 0).width;
		while (w < margenMinTexto)
		{
			fuente.loadFont("Sansation_Regular.ttf", fuente.getSize() + razonCambioFuente);
			w = fuente.getStringBoundingBox(texto, 0, 0).width;
		}
	}
}

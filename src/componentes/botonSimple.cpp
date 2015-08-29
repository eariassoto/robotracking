#include "botonSimple.h"
#include <algorithm>
#include <string>
botonSimple::botonSimple(string t, int tamFuente, ofColor c, int x, int y, int w, int h) : componenteBase(x, y, w, h)
{

	fuente.loadFont("opensansfont.ttf", tamFuente);
	texto = t;
	std::transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
	colorFuente = c;

};

void botonSimple::draw()
{
	ofFill();
	ofColor color;
	if (mouseDentro)
	{
		if (leQuedaTiempo)
		{
			// calcula el porcentaje de tiempo que lleva
			// da un numero de 0-99
			int diferencia = (getMillisec() - tiempo);
			double porcentajeActivo = (diferencia * 100) / tiempoMax;

			// este porcentaje lo uso para degradar los canales
			// green y blue (estamos en RGB) para obtener un boton
			// que se hace rojo conforme pasa el tiempo
			color.set((int)(200 - porcentajeActivo), (int)(200 - porcentajeActivo), 200);
		}
		else
		{
			color.set(200, 200, 200);
		}
	}
	else
	{
		color.set(200, 200, 200);
	}

	ofSetColor(color);
	ofRect(x, y, width, height);

	ofSetColor(colorFuente);


	ofRectangle cajaTexto = fuente.getStringBoundingBox(texto, 0, 0);
	float widthTexto = cajaTexto.width;
	float heightTexto = cajaTexto.height;

	float sobranteX = (width - widthTexto) / 2;
	float sobranteY = (height - heightTexto) / 2.0f + (heightTexto);

	fuente.drawString(texto, x + sobranteX, y + sobranteY);

}

string botonSimple::getTexto()
{
	return texto;
}

void botonSimple::setTexto(string t)
{
	texto = t;
}
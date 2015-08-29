#include "botonImagen.h"

botonImagen::botonImagen(string r, float esc, string t, int tamFuente, ofColor c, int x, int y, int w, int h) : componenteBase(x, y, w, h)
{

	fuente.loadFont("opensansfont.ttf", tamFuente);
	texto = t;
	colorFuente = c;

	imagen.loadImage(r);
	escala = esc;
	imagen.resize(w*escala, h*escala);

};

botonImagen::botonImagen(string r, float esc, string t, int tamFuente, ofColor c) : componenteBase(0,0,0,0)
{

	fuente.loadFont("opensansfont.ttf", tamFuente);
	texto = t;
	colorFuente = c;

	imagen.loadImage(r);
	escala = esc;
	

};

void botonImagen::setPos(int x, int y)
{
	componenteBase::setPos(x, y);
}

void botonImagen::setTam(int w, int h)
{
	componenteBase::setTam(w, h);
	imagen.resize(w*escala, h*escala);
}

void botonImagen::draw()
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

	ofSetColor(255, 255, 255);
	float margen = (1 - escala) / 2;
	float posx = x + (width*margen);
	float posy = y + (height*margen);
	imagen.draw(posx, posy);

	ofSetColor(colorFuente);
	ofRectangle cajaTexto = fuente.getStringBoundingBox(texto, 0, 0);
	float widthTexto = cajaTexto.width;
	float heightTexto = cajaTexto.height;

	float sobranteX = (width - widthTexto) / 2;
	float sobranteY = height - (heightTexto / 2);

	fuente.drawString(texto, x + sobranteX, y + sobranteY);


}

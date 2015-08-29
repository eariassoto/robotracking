#pragma once
#include "componenteBase.h"
#include "ofTrueTypeFont.h"
#include "ofImage.h"

/// Bot�n con imagen y texto
/**
	Este bot�n funciona para los entornos que integran pictogramas. Adem�s de tener una
	imagen el bot�n puede tener un texto bajo la imagen.

	La imagen del bot�n es escalada para que quepa dentro del bot�n, tener en consideraci�n que 
	si el bot�n es cuadrado y la imagen es rectangular se va a perder la proporci�n de la imagen. Esto
	es algo que se puede arreglar a la ahora de escalar la imagen en el constructor.
*/
class botonImagen : public componenteBase{

public:

	/// Constructor principal de la clase, define tama�o y posici�n
	/**
	Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

	\param r Localizacion de la imagen
	\param esc Representa la escala entre la imagen y el tama�o del bot�n, n�mero real entre 0 y 1
	\param t texto del bot�n
	\param tamFuente tama�o de la fuente del texto
	\param c color del texto
	\param x localizaci�n en el eje x
	\param y localizaci�n en el eye y
	\param w largo del componente
	\param h ancho del componente
	*/
	botonImagen(string, float, string, int, ofColor, int, int, int, int);

	/// Constructor secundario de la clase, sin tama�o y posici�n definidos
	/**

	\param r Localizacion de la imagen
	\param esc Representa la escala entre la imagen y el tama�o del bot�n, n�mero real entre 0 y 1
	\param t texto del bot�n
	\param tamFuente tama�o de la fuente del texto
	\param c color del texto
	*/
	botonImagen(string, float, string, int, ofColor);

	/// Asigna tama�o al bot�n
	/**
		\param w largo del componente
		\param h ancho del componente
	*/
	void setTam(int, int);

	// Asigna posici�n en la pantalla al bot�n
	/**
		\param x localizaci�n en el eje x
		\param y localizaci�n en el eye y
	*/
	void setPos(int, int);

	void draw();

protected:

	/// Relaci�n de la imagen con respecto al tama�o del bot�n
	float          escala;

	/// Color del texto
	ofColor        colorFuente;

	/// Fuente para dibujar el texto
	ofTrueTypeFont fuente;

	/// Texto que se va a mostrar en la parte interior del bot�n
	string         texto;

	/// Imagen que se va a dibujar en el bot�n
	ofImage        imagen;
};


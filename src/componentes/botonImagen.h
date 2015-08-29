#pragma once
#include "componenteBase.h"
#include "ofTrueTypeFont.h"
#include "ofImage.h"

/// Botón con imagen y texto
/**
	Este botón funciona para los entornos que integran pictogramas. Además de tener una
	imagen el botón puede tener un texto bajo la imagen.

	La imagen del botón es escalada para que quepa dentro del botón, tener en consideración que 
	si el botón es cuadrado y la imagen es rectangular se va a perder la proporción de la imagen. Esto
	es algo que se puede arreglar a la ahora de escalar la imagen en el constructor.
*/
class botonImagen : public componenteBase{

public:

	/// Constructor principal de la clase, define tamaño y posición
	/**
	Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

	\param r Localizacion de la imagen
	\param esc Representa la escala entre la imagen y el tamaño del botón, número real entre 0 y 1
	\param t texto del botón
	\param tamFuente tamaño de la fuente del texto
	\param c color del texto
	\param x localización en el eje x
	\param y localización en el eye y
	\param w largo del componente
	\param h ancho del componente
	*/
	botonImagen(string, float, string, int, ofColor, int, int, int, int);

	/// Constructor secundario de la clase, sin tamaño y posición definidos
	/**

	\param r Localizacion de la imagen
	\param esc Representa la escala entre la imagen y el tamaño del botón, número real entre 0 y 1
	\param t texto del botón
	\param tamFuente tamaño de la fuente del texto
	\param c color del texto
	*/
	botonImagen(string, float, string, int, ofColor);

	/// Asigna tamaño al botón
	/**
		\param w largo del componente
		\param h ancho del componente
	*/
	void setTam(int, int);

	// Asigna posición en la pantalla al botón
	/**
		\param x localización en el eje x
		\param y localización en el eye y
	*/
	void setPos(int, int);

	void draw();

protected:

	/// Relación de la imagen con respecto al tamaño del botón
	float          escala;

	/// Color del texto
	ofColor        colorFuente;

	/// Fuente para dibujar el texto
	ofTrueTypeFont fuente;

	/// Texto que se va a mostrar en la parte interior del botón
	string         texto;

	/// Imagen que se va a dibujar en el botón
	ofImage        imagen;
};


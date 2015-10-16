#pragma once
#include "componenteBase.h"
#include "ofTrueTypeFont.h"
#include "ofColor.h"

/// Caja para mostrar texto
/**
	El texto está centrado y pensado para mostrar máximo una oración, 
	el soporte para párrafos y barras de scroll no están implementados
*/
class cajaTexto : public componenteBase{

public:

	/// Constructor de la clase
	/**
	Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

		\param tamFuente tamaño de la fuente del texto
		\param c color del texto
		\param x localización en el eje x
		\param y localización en el eye y
		\param w largo del componente
		\param h ancho del componente
	*/
	cajaTexto(int, ofColor, int, int, int, int);

	cajaTexto(int, ofColor, int, int, int, int, int);

	void draw();

	/// Agrega texto al final de la hilera actual
	void appendTexto(string);

	/// Borra el último caracter del texto
	void borrarCaracter();

	/// Devuelve el texto actual
	string getTexto();

	void limpiar();

private:

	/// Color del texto
	ofColor colorFuente;

	/// Fuente del texto
	ofTrueTypeFont fuente;

	/// Texto que se está mostrando en la caja
	string texto;

	int margenMaxTexto;
	int margenMinTexto;
	int fuenteInicial;
	int razonCambioFuente;

	int alfa;
	ofColor color;
};


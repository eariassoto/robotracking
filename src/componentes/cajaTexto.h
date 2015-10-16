#pragma once
#include "componenteBase.h"
#include "ofTrueTypeFont.h"
#include "ofColor.h"

/// Caja para mostrar texto
/**
	El texto est� centrado y pensado para mostrar m�ximo una oraci�n, 
	el soporte para p�rrafos y barras de scroll no est�n implementados
*/
class cajaTexto : public componenteBase{

public:

	/// Constructor de la clase
	/**
	Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

		\param tamFuente tama�o de la fuente del texto
		\param c color del texto
		\param x localizaci�n en el eje x
		\param y localizaci�n en el eye y
		\param w largo del componente
		\param h ancho del componente
	*/
	cajaTexto(int, ofColor, int, int, int, int);

	cajaTexto(int, ofColor, int, int, int, int, int);

	void draw();

	/// Agrega texto al final de la hilera actual
	void appendTexto(string);

	/// Borra el �ltimo caracter del texto
	void borrarCaracter();

	/// Devuelve el texto actual
	string getTexto();

	void limpiar();

private:

	/// Color del texto
	ofColor colorFuente;

	/// Fuente del texto
	ofTrueTypeFont fuente;

	/// Texto que se est� mostrando en la caja
	string texto;

	int margenMaxTexto;
	int margenMinTexto;
	int fuenteInicial;
	int razonCambioFuente;

	int alfa;
	ofColor color;
};


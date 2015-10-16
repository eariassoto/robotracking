#pragma once
#include "componenteBase.h"
#include "ofTrueTypeFont.h"

/// Botón con texto
/**
	Este componente representa un botón con una hilera de caracteres. Se pueden controlar parámetros
	como el tamaño de la fuente y el color del texto. El texto se dibuja centrado en el componente.

*/
class botonSimple : public componenteBase{

public:

	/// Constructor de la clase
	/**
		Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

		\param t texto del botón
		\param tamFuente tamaño de la fuente del texto
		\param c color del texto
		\param x localización en el eje x
		\param y localización en el eye y
		\param w largo del componente
		\param h ancho del componente
	*/
	botonSimple(string, int, ofColor, int, int, int, int);

	botonSimple(string, int, ofColor, int, int, int, int, int);

	void draw();

	/// Recupera el texto del botón
	string getTexto();

	/// Cambia el texto del botón
	void setTexto(string);

private:

	/// Color de la fuente
	ofColor colorFuente;
	
	/// Instancia de la fuente para poder dibujar el texto
	ofTrueTypeFont fuente;

	/// Contiene el texto del botón
	string texto;

	int alfa;
};

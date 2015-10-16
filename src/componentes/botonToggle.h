#pragma once
#include "botonImagen.h"

/// Bot�n que alterna dos imagenes y textos
/**
	Este bot�n implementa la funcionalidad de alternar estados. Se definen dos pares de imagenes
	y textos.
*/
class botonToggle: public botonImagen{
	
public:

	/// Constructor principal de la clase, define tama�o y posici�n
	/**
		Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

		\param r1 Localizacion de la imagen 1
		\param r2 Localizacion de la imagen 2
		\param esc Representa la escala entre la imagen y el tama�o del bot�n, n�mero real entre 0 y 1
		\param t1 texto 1 del bot�n
		\param t2 texto 2 del bot�n
		\param tamFuente tama�o de la fuente del texto
		\param c color del texto
		\param x localizaci�n en el eje x
		\param y localizaci�n en el eye y
		\param w_ largo del componente
		\param h_ ancho del componente
	*/
	botonToggle(string, string, float, string, string, int, ofColor, int, int, int, int);

	/// Constructor secundario de la clase, sin tama�o y posici�n definidos
	/**

		\param r1 Localizacion de la imagen 1
		\param r2 Localizacion de la imagen 2
		\param esc Representa la escala entre la imagen y el tama�o del bot�n, n�mero real entre 0 y 1
		\param t1 texto 1 del bot�n
		\param t2 texto 2 del bot�n
		\param tamFuente tama�o de la fuente del texto
		\param c color del texto
	*/
	botonToggle(string, string, float, string, string, int, ofColor);

	/// Implementa el cambio de imagen y texto si el usuario hizo clic
	/**
		\param x coordenada x del componente de gestos
		\param y coordenada y del componente de gestos
		\param c indica si el usuario ha hecho el gesto para el clic

		\return true si el usuario hizo clic sobre el componente
	*/
	bool update(float, float, bool);

	/// Implementa el cambio de imagen y texto si el usuario hizo clic
	/**
	\param x coordenada x de la entrada
	\param y coordenada y de la entrada

	\return true si el usuario hizo clic sobre el componente
	*/
	bool update(float, float);

	/// Devuelve el estado del bot�n
	/**
		\return true si el bot�n est� en el estado 2
	*/
	bool state();

	/// Cambia el estado del bot�n
	void toggle();

private:

	/// Define el estado del bot�n, se inicializa en false
	bool   toggleState;

	/// Localizaci�n de la imagen del estado 1
	string ruta1;

	/// Localizaci�n de la imagen del estado 2
	string ruta2;

	/// Texto del estado 1
	string texto1;

	/// Texto del estado 2
	string texto2;

	/// Escalas de las imagenes
	float  escala;

	/// Largo del bot�n
	int w;

	/// Ancho del bot�n
	int h;

	bool update(bool);
};
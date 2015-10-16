#pragma once
#include "botonImagen.h"

/// Botón que alterna dos imagenes y textos
/**
	Este botón implementa la funcionalidad de alternar estados. Se definen dos pares de imagenes
	y textos.
*/
class botonToggle: public botonImagen{
	
public:

	/// Constructor principal de la clase, define tamaño y posición
	/**
		Inicializa la fuente y guarda las configuraciones necesarias para dibujarse en pantalla.

		\param r1 Localizacion de la imagen 1
		\param r2 Localizacion de la imagen 2
		\param esc Representa la escala entre la imagen y el tamaño del botón, número real entre 0 y 1
		\param t1 texto 1 del botón
		\param t2 texto 2 del botón
		\param tamFuente tamaño de la fuente del texto
		\param c color del texto
		\param x localización en el eje x
		\param y localización en el eye y
		\param w_ largo del componente
		\param h_ ancho del componente
	*/
	botonToggle(string, string, float, string, string, int, ofColor, int, int, int, int);

	/// Constructor secundario de la clase, sin tamaño y posición definidos
	/**

		\param r1 Localizacion de la imagen 1
		\param r2 Localizacion de la imagen 2
		\param esc Representa la escala entre la imagen y el tamaño del botón, número real entre 0 y 1
		\param t1 texto 1 del botón
		\param t2 texto 2 del botón
		\param tamFuente tamaño de la fuente del texto
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

	/// Devuelve el estado del botón
	/**
		\return true si el botón está en el estado 2
	*/
	bool state();

	/// Cambia el estado del botón
	void toggle();

private:

	/// Define el estado del botón, se inicializa en false
	bool   toggleState;

	/// Localización de la imagen del estado 1
	string ruta1;

	/// Localización de la imagen del estado 2
	string ruta2;

	/// Texto del estado 1
	string texto1;

	/// Texto del estado 2
	string texto2;

	/// Escalas de las imagenes
	float  escala;

	/// Largo del botón
	int w;

	/// Ancho del botón
	int h;

	bool update(bool);
};
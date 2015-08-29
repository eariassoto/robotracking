#pragma once
#include "espacioBase.h"
#include "ofVideoGrabber.h"
#include "botonImagen.h"

/// Espacio para tomar fotos por medio de la cámara
/**
Este espacio define un tipo de comunicación para un usuario que posea capacidades
de lectoescritura, este espacio puede mejorarse y adaptarse a las necesidades del
usuario.

*/
class espacioCamara : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		\param espacioPadre Puntero al menú de la categoría
	*/
	espacioCamara(espacioBase*);

	/// Destructor de la clase
	~espacioCamara();

	void setup();
	espacioBase* update(float, float, float, float, bool);
	void draw();

private:

	/// Largo de la imagen de la cámara
	int            camWidth;

	/// Ancho de la imagen de la cámara
	int            camHeight;

	/// Coordenada x de la imagen de la cámara
	double         camX;

	/// Coordenada y de la imagen de la cámara
	double         camY;

	/// Instancia del manejador de la cámara
	ofVideoGrabber vidGrabber;

	/// Captura de la cámara que se mostrando al usuario
	ofImage        img;

	/// Botón para salir al menú
	botonImagen    *btnAtras;

	/// Botón para tomar una foto
	botonImagen    *btnFoto;

	/// Botón para acceder a la galería
	botonImagen    *btnGaleria;
};

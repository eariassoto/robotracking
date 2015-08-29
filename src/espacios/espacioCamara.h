#pragma once
#include "espacioBase.h"
#include "ofVideoGrabber.h"
#include "botonImagen.h"

/// Espacio para tomar fotos por medio de la c�mara
/**
Este espacio define un tipo de comunicaci�n para un usuario que posea capacidades
de lectoescritura, este espacio puede mejorarse y adaptarse a las necesidades del
usuario.

*/
class espacioCamara : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		\param espacioPadre Puntero al men� de la categor�a
	*/
	espacioCamara(espacioBase*);

	/// Destructor de la clase
	~espacioCamara();

	void setup();
	espacioBase* update(float, float, float, float, bool);
	void draw();

private:

	/// Largo de la imagen de la c�mara
	int            camWidth;

	/// Ancho de la imagen de la c�mara
	int            camHeight;

	/// Coordenada x de la imagen de la c�mara
	double         camX;

	/// Coordenada y de la imagen de la c�mara
	double         camY;

	/// Instancia del manejador de la c�mara
	ofVideoGrabber vidGrabber;

	/// Captura de la c�mara que se mostrando al usuario
	ofImage        img;

	/// Bot�n para salir al men�
	botonImagen    *btnAtras;

	/// Bot�n para tomar una foto
	botonImagen    *btnFoto;

	/// Bot�n para acceder a la galer�a
	botonImagen    *btnGaleria;
};

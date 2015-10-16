#pragma once
#include "espacioBase.h"
#include "botonImagen.h"
#include "botonToggle.h"
#include "menuComunicacion.h"
#include "menuEducacion.h"
#include "menuOcio.h"
#include "menuCotidiana.h"
#include "ofImage.h"

/// Men� principal de la aplicaci�n
/**
	Este men� no tiene archivo de configuraci�n sino que los botones est�n definidos
	manualmente. Cualquier submen� nuevo deber ser agregado ac�.
*/
class menuPrincipal : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Define el modo en que el usuario va a interactuar, ya sea por visi�n o por gestos.
	*/
	menuPrincipal();

	/// Destructor de la clase
	~menuPrincipal();

	void         setup();
	espacioBase* update(float, float);
	espacioBase* update(float, float, bool);
	void         draw();

	/// Bot�n paa cambiar el modo de reconocimiento
	botonToggle *btnInput;

	

private:

	/// Instancia del men� de comunicaci�n
	menuComunicacion  *mComunicacion;

	/// Instancia del men� de vida cotidiana
	menuCotidiana     *mCotidiana;

	/// Instancia del men� de ocio
	menuOcio          *mOcio;

	/// Instancia del men� de educaci�n
	menuEducacion     *mEducacion;

	/// Fuente del texto
	ofTrueTypeFont fuente;

	/// Logo de la aplicaci�n
	ofImage logo;

	/// Coordenada x del logo
	float logox;

	/// Coordenada y del logo
	float logoy;

	/// Bot�n de la categor�a comunicaci�n
	botonImagen *btnComunicacion;

	/// Bot�n de la categor�a educaci�n
	botonImagen *btnEducacion;

	/// Bot�n de la categor�a vida cotidiana
	botonImagen *btnCotidiana;

	/// Bot�n de la categor�a ocio
	botonImagen *btnOcio;

	/// Bot�n para salir de la aplicaci�n
	botonImagen *btnSalir;

	espacioBase* update(bool, bool, bool, bool, bool, bool);
	
};


#pragma once
#include "espacioBase.h"
#include "botonImagen.h"
#include "botonToggle.h"
#include "menuComunicacion.h"
#include "menuEducacion.h"
#include "menuOcio.h"
#include "menuCotidiana.h"
#include "ofImage.h"

/// Menú principal de la aplicación
/**
	Este menú no tiene archivo de configuración sino que los botones están definidos
	manualmente. Cualquier submenú nuevo deber ser agregado acá.
*/
class menuPrincipal : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Define el modo en que el usuario va a interactuar, ya sea por visión o por gestos.
	*/
	menuPrincipal();

	/// Destructor de la clase
	~menuPrincipal();

	void         setup();
	espacioBase* update(float, float);
	espacioBase* update(float, float, bool);
	void         draw();

	/// Botón paa cambiar el modo de reconocimiento
	botonToggle *btnInput;

	

private:

	/// Instancia del menú de comunicación
	menuComunicacion  *mComunicacion;

	/// Instancia del menú de vida cotidiana
	menuCotidiana     *mCotidiana;

	/// Instancia del menú de ocio
	menuOcio          *mOcio;

	/// Instancia del menú de educación
	menuEducacion     *mEducacion;

	/// Fuente del texto
	ofTrueTypeFont fuente;

	/// Logo de la aplicación
	ofImage logo;

	/// Coordenada x del logo
	float logox;

	/// Coordenada y del logo
	float logoy;

	/// Botón de la categoría comunicación
	botonImagen *btnComunicacion;

	/// Botón de la categoría educación
	botonImagen *btnEducacion;

	/// Botón de la categoría vida cotidiana
	botonImagen *btnCotidiana;

	/// Botón de la categoría ocio
	botonImagen *btnOcio;

	/// Botón para salir de la aplicación
	botonImagen *btnSalir;

	espacioBase* update(bool, bool, bool, bool, bool, bool);
	
};


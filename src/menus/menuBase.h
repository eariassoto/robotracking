#pragma once
#include "ofxXmlSettings.h"
#include "espacioBase.h"
#include "botonImagen.h"
#include "ofImage.h"
#include <vector>

using std::vector;

/// Base para los menús de la aplicación
/**
	Se pretende que los espacios de la aplicación se agrupen en categorías. Cada categoría tendrá su
	menú. Todos los menús heredan de esta clase para que se mantenga el mismo estilo. Cualquier cambio
	estético que se quisiera aplicar a todos los menús deberían integrarse acá.

	Cada menú tiene su propio archivos de configuraciones. Este archivo tiene un formato XML e indica los componentes que tendrá
	el menú. Además, los menús tienen las instancias de los espacios que están relacionados a su categoría.

*/
class menuBase : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Carga el archivo de configuración.

		\param confPath Localización del archivo de configuración
		\param espPadre Puntero al espacio/menú padre del menú 
	*/
	menuBase(string, espacioBase*);

	/// Destructor de la clase
	~menuBase();

	void         setup();
	espacioBase* update(float, float);
	espacioBase* update(float, float, bool);
	void          draw();

protected:

	/// Fuente del texto
	ofTrueTypeFont fuente;

	/// Logo de la aplicación
	ofImage logo;

	/// Coordenada x del logo
	float logox;
	
	/// Coordenada y del logo
	float  logoy;

	/// Instancia que maneja las configuraciones desde un archivo XML
	ofxXmlSettings configuraciones;

	/// Botones que llevan al usuario a los espacios del menú
	vector<botonImagen> btn;

	/// Botón para que el usuario se devuelva en la aplicación
	botonImagen *btnAtras;

	/// Maneja los eventos de los botones
	/**
		Cada menú tiene una cantidad determinada de botones. Para cada uno de ellos
		se implementa un evento que se dispara cuando el usuario hace clic

		\param index Indice del boton en la lista btn
	*/
	virtual espacioBase* eventos(int index) = 0;
	
	espacioBase* update(bool);
};


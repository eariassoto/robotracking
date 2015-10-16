#pragma once
#include "ofxXmlSettings.h"
#include "espacioBase.h"
#include "botonImagen.h"
#include "ofImage.h"
#include <vector>

using std::vector;

/// Base para los men�s de la aplicaci�n
/**
	Se pretende que los espacios de la aplicaci�n se agrupen en categor�as. Cada categor�a tendr� su
	men�. Todos los men�s heredan de esta clase para que se mantenga el mismo estilo. Cualquier cambio
	est�tico que se quisiera aplicar a todos los men�s deber�an integrarse ac�.

	Cada men� tiene su propio archivos de configuraciones. Este archivo tiene un formato XML e indica los componentes que tendr�
	el men�. Adem�s, los men�s tienen las instancias de los espacios que est�n relacionados a su categor�a.

*/
class menuBase : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Carga el archivo de configuraci�n.

		\param confPath Localizaci�n del archivo de configuraci�n
		\param espPadre Puntero al espacio/men� padre del men� 
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

	/// Logo de la aplicaci�n
	ofImage logo;

	/// Coordenada x del logo
	float logox;
	
	/// Coordenada y del logo
	float  logoy;

	/// Instancia que maneja las configuraciones desde un archivo XML
	ofxXmlSettings configuraciones;

	/// Botones que llevan al usuario a los espacios del men�
	vector<botonImagen> btn;

	/// Bot�n para que el usuario se devuelva en la aplicaci�n
	botonImagen *btnAtras;

	/// Maneja los eventos de los botones
	/**
		Cada men� tiene una cantidad determinada de botones. Para cada uno de ellos
		se implementa un evento que se dispara cuando el usuario hace clic

		\param index Indice del boton en la lista btn
	*/
	virtual espacioBase* eventos(int index) = 0;
	
	espacioBase* update(bool);
};


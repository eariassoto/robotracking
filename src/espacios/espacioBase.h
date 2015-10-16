#pragma once
#include <string>
#include "ofTrueTypeFont.h"
#include "ofGraphics.h"

using namespace std;

/// Clase base para todos los espacios de la aplicación
/**
	Un espacio de la aplicación se puede ver como una pantalla. Cada pantalla está ligada a un
	contexto en común de la aplicación. Así pues, los espacios nuevos deben de herededar de esta 
	clase base e implementar los debidos métodos virtuales. Si se quieren implementar los otros
	métodos de OpenGL es recomendado que se declaren aquí pero no de manera virtual para no afectar
	el comportamiento de los espacios que ya existen.
*/
class espacioBase
{

public:
	/// Constructor de la clase
	/**
		El constructor base guarda el puntero al espacio padre. Esto porque el esquema de la 
		aplicación se ve como una jerarquía. El espacio base es el menu principal, este a su vez es
		padre de los submenús y estos son padres de los espacios funcionales de la aplicación.
		Este esquema debe ser respetado cuando se creen nuevos espacios.
	*/
	espacioBase(espacioBase*);

	/// Método inicial del ciclo de OpenGL
	virtual void setup() = 0;

	/// Controla tareas lógica de cada ciclo de OpenGL, version leap
	virtual espacioBase* update(float, float, bool) = 0;

	/// Controla tareas lógica de cada ciclo de OpenGL, version tobii
	virtual espacioBase* update(float, float) = 0;

	/// Controla las tareas gráficas de cada ciclo de OpenGL
	virtual void draw() = 0;

protected:

	/// Puntero al espacio que se encarga de llamarlo
	/**
		Este puntero es útil para cuando el usuario decide salir del espacio activo. Cualquier 
		cambio de este comportamiento debería ser implementado de forma complementaria en esta 
		clase.
	*/
	espacioBase* espacioPadre;

};


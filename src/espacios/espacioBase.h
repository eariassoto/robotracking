#pragma once
#include <string>
#include "ofTrueTypeFont.h"
#include "ofGraphics.h"

using namespace std;

/// Clase base para todos los espacios de la aplicaci�n
/**
	Un espacio de la aplicaci�n se puede ver como una pantalla. Cada pantalla est� ligada a un
	contexto en com�n de la aplicaci�n. As� pues, los espacios nuevos deben de herededar de esta 
	clase base e implementar los debidos m�todos virtuales. Si se quieren implementar los otros
	m�todos de OpenGL es recomendado que se declaren aqu� pero no de manera virtual para no afectar
	el comportamiento de los espacios que ya existen.
*/
class espacioBase
{

public:
	/// Constructor de la clase
	/**
		El constructor base guarda el puntero al espacio padre. Esto porque el esquema de la 
		aplicaci�n se ve como una jerarqu�a. El espacio base es el menu principal, este a su vez es
		padre de los submen�s y estos son padres de los espacios funcionales de la aplicaci�n.
		Este esquema debe ser respetado cuando se creen nuevos espacios.
	*/
	espacioBase(espacioBase*);

	/// M�todo inicial del ciclo de OpenGL
	virtual void setup() = 0;

	/// Controla tareas l�gica de cada ciclo de OpenGL, version leap
	virtual espacioBase* update(float, float, bool) = 0;

	/// Controla tareas l�gica de cada ciclo de OpenGL, version tobii
	virtual espacioBase* update(float, float) = 0;

	/// Controla las tareas gr�ficas de cada ciclo de OpenGL
	virtual void draw() = 0;

protected:

	/// Puntero al espacio que se encarga de llamarlo
	/**
		Este puntero es �til para cuando el usuario decide salir del espacio activo. Cualquier 
		cambio de este comportamiento deber�a ser implementado de forma complementaria en esta 
		clase.
	*/
	espacioBase* espacioPadre;

};


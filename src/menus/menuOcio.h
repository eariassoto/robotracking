#pragma once
#include "menuBase.h"
#include "espacioCamara.h"

/// Menú de la categoría ocio
class menuOcio : public menuBase{

public:

	/// Constructor de la clase
	/**
		\param mPadre puntero al menú principal
	*/
	menuOcio(espacioBase*);

	/// Destructor de la clase
	~menuOcio();

	void setup();

protected:

	espacioBase*  eventos(int);

	/// Instancia del espacio cámara
	espacioCamara *espCamara;

};
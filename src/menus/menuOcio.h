#pragma once
#include "menuBase.h"
#include "espacioCamara.h"

/// Men� de la categor�a ocio
class menuOcio : public menuBase{

public:

	/// Constructor de la clase
	/**
		\param mPadre puntero al men� principal
	*/
	menuOcio(espacioBase*);

	/// Destructor de la clase
	~menuOcio();

	void setup();

protected:

	espacioBase*  eventos(int);

	/// Instancia del espacio c�mara
	espacioCamara *espCamara;

};
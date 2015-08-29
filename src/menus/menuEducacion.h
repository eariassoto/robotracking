#pragma once
#include "menuBase.h"
#include "espacioTarjetas.h"

/// Men� de la categor�a educaci�n
class menuEducacion : public menuBase{

public:

	/// Constructor de la clase
	/**
	\param mPadre puntero al men� principal
	*/
	menuEducacion(espacioBase* mPadre) : menuBase("menus/menuEducacion.xml", mPadre){};

	/// Destructor de la clase
	~menuEducacion();
	void setup();

protected:

	espacioBase* eventos(int);

	/// Instancia del espacio tarjetas
	espacioTarjetas *tarjetas;

};
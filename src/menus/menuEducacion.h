#pragma once
#include "menuBase.h"
#include "espacioTarjetas.h"

/// Menú de la categoría educación
class menuEducacion : public menuBase{

public:

	/// Constructor de la clase
	/**
	\param mPadre puntero al menú principal
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
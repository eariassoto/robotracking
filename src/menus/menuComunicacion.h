#pragma once
#include "menuBase.h"
#include "espacioTeclado.h"
#include "espacioPictograma.h"
#include "espacioSiNo.h"

/// Men� de la categor�a comunicaci�n
class menuComunicacion : public menuBase{

public:

	/// Constructor de la clase
	/**
	\param mPadre puntero al men� principal
	*/
	menuComunicacion(espacioBase* mPadre) : menuBase("menus/menuComunicacion.xml", mPadre){};

	/// Destructor de la clase
	~menuComunicacion();

	void setup();
private:

	espacioBase*      eventos(int);

	/// Instancia del espacio teclado
	espacioTeclado    *espTeclado;
	
	/// Instancia del espacio pictogramas
	espacioPictograma *espPictograma;

	/// Instancia del espacio si/no
	espacioSiNo       *espSiNo;

};
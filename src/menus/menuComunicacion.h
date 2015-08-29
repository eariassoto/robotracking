#pragma once
#include "menuBase.h"
#include "espacioTeclado.h"
#include "espacioPictograma.h"
#include "espacioSiNo.h"

/// Menú de la categoría comunicación
class menuComunicacion : public menuBase{

public:

	/// Constructor de la clase
	/**
	\param mPadre puntero al menú principal
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
#pragma once
#include "menuBase.h"

/// Menú de la categoría vida cotidiana
class menuCotidiana : public menuBase{

public:

	/// Constructor de la clase
	/**
	\param mPadre puntero al menú principal
	*/
	menuCotidiana(espacioBase* mPadre) : menuBase("menus/menuCotidiana.xml", mPadre){};

protected:

	espacioBase* eventos(int);
};
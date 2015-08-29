#pragma once
#include "menuBase.h"

/// Men� de la categor�a vida cotidiana
class menuCotidiana : public menuBase{

public:

	/// Constructor de la clase
	/**
	\param mPadre puntero al men� principal
	*/
	menuCotidiana(espacioBase* mPadre) : menuBase("menus/menuCotidiana.xml", mPadre){};

protected:

	espacioBase* eventos(int);
};
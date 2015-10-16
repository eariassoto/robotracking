#pragma once
#include "espacioBase.h"
#include "botonImagen.h"

/// Espacio de comunicaci�n b�sica
/**
	Este espacio ejemplifica un el m�todo m�s simple para comunicarse. El usuario fija su atenci�n
	en dos puntos, un lugar indica s� y otro indica no.
*/
class espacioSiNo : public espacioBase
{

public:

	/// Constructor de la clase
	espacioSiNo(espacioBase*);

	/// Destructor de la clase
	~espacioSiNo();

	void setup();
	espacioBase* update(float, float);
	espacioBase* update(float, float, bool);
	void draw();

private:

	/// Fuente para dibujar texto en pantalla
	ofTrueTypeFont fuenteSiNo;

	botonImagen *btnAtras;

	espacioBase* update(bool);
};


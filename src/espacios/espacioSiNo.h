#pragma once
#include "espacioBase.h"
#include "botonImagen.h"

/// Espacio de comunicación básica
/**
	Este espacio ejemplifica un el método más simple para comunicarse. El usuario fija su atención
	en dos puntos, un lugar indica sí y otro indica no.
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


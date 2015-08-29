#pragma once
#include "ofxXmlSettings.h"

/// Ayuda a enviar peticiones a un Arduino Yun
class conexionYun{

public:

	/// Constructor de la clase
	conexionYun(string);

	/// Env�a una petici�n al Arduino
	string enviarPeticion(string);

private:

	/// Contiene las configuraciones del puerto del Arduino
	ofxXmlSettings conf;

	/// Direcci�n en la que se encuentra el servidor del Yun
	string direccionBase;
};
#pragma once
#include <vector>
#include "ofxXmlSettings.h"
#include "espacioBase.h"
#include "fabricaComponentes.h"
#include "botonImagen.h"

using namespace std;

/// Espacio de comunicaci�n por medio de lecto escritura
/**
	Este espacio define un tipo de comunicaci�n para un usuario que posea capacidades
	de lectoescritura, este espacio puede mejorarse y adaptarse a las necesidades del 
	usuario.

*/
class espacioTeclado : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Esta clase implementa un archivo de configuraci�n para cargar los botones. Como
		el espacio implementa un teclado con muchos botones es mejor definirlos din�micamente.

		\param confPath archivo de configuraci�n
		\param espacioPadre puntero al espacio padre
	*/
	espacioTeclado(string, espacioBase*);

	/// Destructor de la clase
	~espacioTeclado();

	void         setup();
	espacioBase* update(float, float, bool);
	espacioBase* update(float, float);
	void         draw();

private:

	/// Env�a el texto al sintetizador de voz
	void comandoHablar(string);

	/// Instancia del manejador del archivo de configuraciones
	ofxXmlSettings  configuraciones;

	/// Fabrica los componentes a partir de las configuraciones
	fabricaComponentes fabComponentes;

	/// Cantidad de componentes en la pantalla
	int cantidadComponentes;

	/// Lista con los componentes cargados de las configuraciones
	vector<componenteBase*> componentes;

	/// Caja de texto para mostrar la hilera que produce el usuario
	cajaTexto *cTexto;

	cajaTexto *tooltip;

	/// Bot�n para borrar el �ltimo caracter
	botonSimple *btnBorrar;

	/// Bot�n para insertar un nuevo espacio
	botonSimple *btnEspacio;

	/// Bot�n para pasar la hilera a voz
	botonSimple *btnHablar;

	botonSimple *btnLimpiar;

	/// Bot�n para salir al men�
	botonImagen *btnSalir;

	espacioBase* update(bool, bool, bool, bool, bool);
};

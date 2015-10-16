#pragma once
#include <vector>
#include "ofxXmlSettings.h"
#include "espacioBase.h"
#include "fabricaComponentes.h"
#include "botonImagen.h"

using namespace std;

/// Espacio de comunicación por medio de lecto escritura
/**
	Este espacio define un tipo de comunicación para un usuario que posea capacidades
	de lectoescritura, este espacio puede mejorarse y adaptarse a las necesidades del 
	usuario.

*/
class espacioTeclado : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Esta clase implementa un archivo de configuración para cargar los botones. Como
		el espacio implementa un teclado con muchos botones es mejor definirlos dinámicamente.

		\param confPath archivo de configuración
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

	/// Envía el texto al sintetizador de voz
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

	/// Botón para borrar el último caracter
	botonSimple *btnBorrar;

	/// Botón para insertar un nuevo espacio
	botonSimple *btnEspacio;

	/// Botón para pasar la hilera a voz
	botonSimple *btnHablar;

	botonSimple *btnLimpiar;

	/// Botón para salir al menú
	botonImagen *btnSalir;

	espacioBase* update(bool, bool, bool, bool, bool);
};

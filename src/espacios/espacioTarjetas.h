#pragma once
#include "espacioBase.h"
#include "botonImagen.h"
#include "botonSimple.h"
#include "sqlite3Manager.h"
#include <vector>

/// Espacio educativo donde se identifican pictogramas con su definici�n en palabras
/**
	El usuario tiene acceso a un estilo de marque con equis, en el cual se le muesta un pictograma
	y 4 palabra(s). Una de la las opciones es correcta. Cuando el usuario acierta, puede volver a 
	intentar con otro pictograma distinto.

	Los s�mbolos pictogr�ficos utilizados de ARASAAC (http://catedu.es/arasaac/) son parte de
	una obra colectiva propiedad de la Diputaci�n General de Arag�n y han creados bajo licencia
	Creative Commons.

*/
class espacioTarjetas : public espacioBase
{

public:

	/// Constructor de la clase
	espacioTarjetas(espacioBase*);

	/// Destructor de la clase
	~espacioTarjetas();

	void setup();
	espacioBase* update(float, float);
	espacioBase* update(float, float, bool);
	void draw();

private:

	/// Carga un ejercicio en pantalla
	void cargarTarjeta();

	/// Verifica si la respuesta elegida por el usuario es correcta
	void validarRespuesta(botonSimple*);

	/// Lista con todos los pictogramas posibles
	/**
		Esta lista se carga por medio de la base de datos sqlite
		*/
	vector<vector<string>> tarjetas;

	/// Pictograma activo que se le muestra al usuario
	ofImage                img;

	/// Respuestas para el pictograma activo
	vector<int>            resp;

	/// Tipo de fuente 1
	ofTrueTypeFont         fuenteResp;

	/// Tipo de fuente 2
	ofTrueTypeFont         fuenteResp2;

	/// Tipo de fuente 3
	ofTrueTypeFont         fuenteResp3;

	/// Bot�n para ir al men� de la categor�a
	botonImagen            *btnAtras;

	/// Bot�n para la opci�n 1
	botonSimple            *btn0;

	/// Bot�n para la opci�n 2
	botonSimple            *btn1;

	/// Bot�n para la opci�n 3
	botonSimple            *btn2;

	/// Bot�n para la opci�n 4
	botonSimple            *btn3;

	/// Bot�n para un nuevo ejercicio
	botonSimple            *btnNuevo;

	/// Indica si el usuario encontr� la soluci�n
	bool                   correcto;

	/// Indica si el usuario escogi� una respuesta incorrecta
	bool                   incorrecto;

	/// Instancia del administrador de la base de datos
	sqlite3Manager *baseDatos;

	espacioBase* update(bool, bool, bool, bool, bool, bool);
};

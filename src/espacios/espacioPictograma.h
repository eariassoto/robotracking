#pragma once
#include <vector>
#include "espacioBase.h"
#include "botonImagen.h"
#include "botonSimple.h"
#include "sqlite3Manager.h"

using std::vector;

/// Espacio de comunicaci�n por medio de pictogramas
/**

	En este espacio se utliza la metodolog�a de pictogramas como medio de comunicaci�n. 
	Un pictograma es un dibujo o gr�fico que expresa un concepto relacionado con el objeto 
	al que se refiere. (https://es.wikipedia.org/wiki/Pictograma)

	La informaci�n de los pictogramas est�n almacenados en una base de datos sqlite. La 
	estructura del espacio consiste en categor�as de pictogramas y sus respectivos gr�ficos. 
	El usuario puede formar sus oraciones y luego enviarlas a texto por voz.

	Los s�mbolos pictogr�ficos utilizados de ARASAAC (http://catedu.es/arasaac/) son parte de 
	una obra colectiva propiedad de la Diputaci�n General de Arag�n y han creados bajo licencia 
	Creative Commons.

*/
class espacioPictograma : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Carga la informaci�n de los programas desde la base de datos
	*/
	espacioPictograma(espacioBase*);

	/// Destructor de la clase
	~espacioPictograma();

	/// M�todo inicial del ciclo de OpenGL
	/**
		Crea los botones de la categor�as, los componentes del espacio y construye los botones
		de los pictogramas activos.
	*/
	void         setup();
	espacioBase* update(float, float, float, float, bool);
	void         draw();

private:

	/// Recupera un pictograma de la lista cuya categor�a est� activa
	vector<string> getPictograma(int);

	/// Carga los botones con los pictogramas activos
	/**
		Por medio de una variable se mantiene un indice de los pictogramas activos. Por ejemplo,
		el indice comienza en 0 y por tanto estan activos los pictogramas 0, 1, 2 y 3 de la categor�a
		activa. Si el �ndice avanza se mostrar�an los pictogramas 4, 5, 6 y 7 y as� hasta llegar al final
		de la lista. Con cada cambio de categor�a el �ndice se reinicia.
	*/
	void           cargarPictogramas();
	
	/// Recupera la cantidad de pictogramas en una lista
	int            getTamPictograma();

	/// Comando temporal para texto por voz
	void           comandoHablar(string s);

	botonImagen *btnAtras;
	botonImagen *btnAdelante;
	botonImagen *btnHablar;
	botonImagen *btnSalir;
	botonImagen *btnBorrar;
	botonImagen *btnBorrarTodo;

	/// Instancia del administrador de la base de datos
	sqlite3Manager *baseDatos;
	
	/// Lista con las categorias disponibles
	vector<botonImagen> btnCategorias;

	/// Lista con los pictogramas activos
	vector<botonImagen> pictogramasActivos;

	int tam, margen, offsetX, offsetY;

	/// Determina si el usuario puede devolver la lista de pictogramas
	bool btnAtrasVisible;
	
	/// Determina si el usuario puede continuar en la lista de pictogramas
	bool btnAdelanteVisible;

	/// Matriz con la informaci�n de las categor�as
	vector<vector<string>> strCategorias;

	/// Lista de matrices con la informaci�n de los pictogramas
	/**
		La lista 0 corresponde a la categor�a 0 y as� sucesivamente para las n categor�as que
		esten cargadas en strCategorias
	*/
	vector<vector<vector<string>>> strPictogramas;

	/// Lista con los pictogramas activos en la pantalla
	vector<pair<string, ofImage>> pictogramasActuales;

	/// Indica el desplazamiento que ha hehco el usuario en la lista de pictogramas
	int indice;

	/// Indica la categor�a activa en la pantalla
	int categoriaActual;
	

	
};
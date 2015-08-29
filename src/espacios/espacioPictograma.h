#pragma once
#include <vector>
#include "espacioBase.h"
#include "botonImagen.h"
#include "botonSimple.h"
#include "sqlite3Manager.h"

using std::vector;

/// Espacio de comunicación por medio de pictogramas
/**

	En este espacio se utliza la metodología de pictogramas como medio de comunicación. 
	Un pictograma es un dibujo o gráfico que expresa un concepto relacionado con el objeto 
	al que se refiere. (https://es.wikipedia.org/wiki/Pictograma)

	La información de los pictogramas están almacenados en una base de datos sqlite. La 
	estructura del espacio consiste en categorías de pictogramas y sus respectivos gráficos. 
	El usuario puede formar sus oraciones y luego enviarlas a texto por voz.

	Los símbolos pictográficos utilizados de ARASAAC (http://catedu.es/arasaac/) son parte de 
	una obra colectiva propiedad de la Diputación General de Aragón y han creados bajo licencia 
	Creative Commons.

*/
class espacioPictograma : public espacioBase
{

public:

	/// Constructor de la clase
	/**
		Carga la información de los programas desde la base de datos
	*/
	espacioPictograma(espacioBase*);

	/// Destructor de la clase
	~espacioPictograma();

	/// Método inicial del ciclo de OpenGL
	/**
		Crea los botones de la categorías, los componentes del espacio y construye los botones
		de los pictogramas activos.
	*/
	void         setup();
	espacioBase* update(float, float, float, float, bool);
	void         draw();

private:

	/// Recupera un pictograma de la lista cuya categoría está activa
	vector<string> getPictograma(int);

	/// Carga los botones con los pictogramas activos
	/**
		Por medio de una variable se mantiene un indice de los pictogramas activos. Por ejemplo,
		el indice comienza en 0 y por tanto estan activos los pictogramas 0, 1, 2 y 3 de la categoría
		activa. Si el índice avanza se mostrarían los pictogramas 4, 5, 6 y 7 y así hasta llegar al final
		de la lista. Con cada cambio de categoría el índice se reinicia.
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

	/// Matriz con la información de las categorías
	vector<vector<string>> strCategorias;

	/// Lista de matrices con la información de los pictogramas
	/**
		La lista 0 corresponde a la categoría 0 y así sucesivamente para las n categorías que
		esten cargadas en strCategorias
	*/
	vector<vector<vector<string>>> strPictogramas;

	/// Lista con los pictogramas activos en la pantalla
	vector<pair<string, ofImage>> pictogramasActuales;

	/// Indica el desplazamiento que ha hehco el usuario en la lista de pictogramas
	int indice;

	/// Indica la categoría activa en la pantalla
	int categoriaActual;
	

	
};
#pragma once
#include <time.h>
#include <chrono>
#include "ofRectangle.h"
#include "ofGraphics.h"

/// Esquema base de los componentes de los espacios
/**
	Los espacios están orientados al uso de botones con texto y/o imágenes para la interacción
	con el usuario. Esta clase hereda de ofRectangle para tener instancias de elementos rectangulares.
	Si se deseara un componente con otra forma geométrica es recomendable quitarle la herencia a esta
	clase y hacer una clase base para los componentes rectangulares.
*/
class componenteBase : public ofRectangle
{

public:

	/// Constructor de la clase
	/**
		Todas las inicializaciones se realizan en este método. Por simpleza se omite la implementación
		de los métodos setup()

		\param _x localización en el eje x
		\param _y localización en el eye y
		\param _w largo del componente
		\param _h ancho del componente
	*/
	componenteBase(int, int, int, int);

	/// Cambia el tamaño del componente
	/**
		\param _w largo del componente
		\param _h ancho del componente
	*/
	void setTam(int, int);

	/// Reposiciona el componente
	/**
		\param _x localización en el eje x
		\param _y localización en el eye y
	*/
	void setPos(int, int);

	/// Actualiza el componente
	/**
		Valida la interacción del usuario con el componente. En caso de reconocimiento visual se usa
		un temporizador. Cuando el usuario fija su atención en el componente corre un temporizador, si
		el usuario mantiene dicha atención por ese tiempo se activa el componente. En caso de reconocimiento
		de gestos se utilizan la posición de entrada y un boolean que indica si el usuario hizo clic.

		\param xIn coordenada x de la entrada visual
		\param yIn coordenada y de la entrada visual
		\param xLea coordenada x del componente de gestos
		\param yLea coordenada y del componente de gestos
		\param clic indica si el usuario ha hecho el gesto para el clic

		\return true si el usuario hizo clic sobre el componente
	*/
	bool         update(float, float, float, float, bool);
	
	/// Dibuja el componente en pantalla
	virtual void draw() = 0;

protected:

	/// Indica si las coordenadas dadas están dentro del componente
	bool          mouseEnCuadro(float, float);

	/// Devuelve el tiempo actual en milisegundos
	long long int getMillisec();

	/// Indica si el usuario está fijando su atención y no ha terminado el tiempo máximo
	bool          leQuedaTiempo;

	/// Indice si el mouse está dentro del componente
	bool          mouseDentro;

	/// Tiempo actual cuando el usuario fija su atención en el componente
	long long int tiempo;

	/// Tiempo máximo para activar el componente 
	int           tiempoMax;

};



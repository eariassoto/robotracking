#pragma once
#include <time.h>
#include <chrono>
#include "ofRectangle.h"
#include "ofGraphics.h"

/// Esquema base de los componentes de los espacios
/**
	Los espacios est�n orientados al uso de botones con texto y/o im�genes para la interacci�n
	con el usuario. Esta clase hereda de ofRectangle para tener instancias de elementos rectangulares.
	Si se deseara un componente con otra forma geom�trica es recomendable quitarle la herencia a esta
	clase y hacer una clase base para los componentes rectangulares.
*/
class componenteBase : public ofRectangle
{

public:

	/// Constructor de la clase
	/**
		Todas las inicializaciones se realizan en este m�todo. Por simpleza se omite la implementaci�n
		de los m�todos setup()

		\param _x localizaci�n en el eje x
		\param _y localizaci�n en el eye y
		\param _w largo del componente
		\param _h ancho del componente
	*/
	componenteBase(int, int, int, int);

	/// Cambia el tama�o del componente
	/**
		\param _w largo del componente
		\param _h ancho del componente
	*/
	void setTam(int, int);

	/// Reposiciona el componente
	/**
		\param _x localizaci�n en el eje x
		\param _y localizaci�n en el eye y
	*/
	void setPos(int, int);

	/// Actualiza el componente
	/**
		Valida la interacci�n del usuario con el componente. En caso de reconocimiento visual se usa
		un temporizador. Cuando el usuario fija su atenci�n en el componente corre un temporizador, si
		el usuario mantiene dicha atenci�n por ese tiempo se activa el componente. En caso de reconocimiento
		de gestos se utilizan la posici�n de entrada y un boolean que indica si el usuario hizo clic.

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

	/// Indica si las coordenadas dadas est�n dentro del componente
	bool          mouseEnCuadro(float, float);

	/// Devuelve el tiempo actual en milisegundos
	long long int getMillisec();

	/// Indica si el usuario est� fijando su atenci�n y no ha terminado el tiempo m�ximo
	bool          leQuedaTiempo;

	/// Indice si el mouse est� dentro del componente
	bool          mouseDentro;

	/// Tiempo actual cuando el usuario fija su atenci�n en el componente
	long long int tiempo;

	/// Tiempo m�ximo para activar el componente 
	int           tiempoMax;

};



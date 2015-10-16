#pragma once
#include "ofMain.h"
#include "espacioBase.h"
#include "menuPrincipal.h"
#include "LeapHost.h"
#include "EyeXHost.h"

/// Clase base que coordina la interacci�n entre el ciclo de OpenGL y la aplicaci�n como tal
/**
	Esta clase se maneja por medio de los eventos establecidos por OpenGL. Cualquier espacio 
	de la aplicacion debe tener al menos implementado los m�todos setup(), update() y draw() 
	para que puedan ser inicializados y dibujados en pantalla. Las dem�s funciones de OpenGL 
	se definen pero se dejan vac�as.
*/
class ofApp : public ofBaseApp
{

public:

	enum class Modo{ Tobii, Leap, Mouse };

	/// Constructor de la clase
	/**
		Por defecto, inicia la aplicaci�n en modo visi�n, sin embargo puede definirse un 
		par�metro de constructor para definir el modo desde el main o leerlo desde un archivo
		de configuraci�n.

		\param m modo de entrada para la instancia de la aplicaci�n
		\param[in] x tama�o del largo de la ventana de la aplicaci�n
		\param[in] y tama�o del ancho de la ventana de la apliaci�n
		\param _hwndWindow manejador de la ventana principal
	*/
	ofApp(Modo, int, int, HWND);

	/// Destructor de la clase
	/**
		Borra a mPrincipal
	*/
	~ofApp();

	/// M�todo inicial del ciclo de OpenGL
	/**
		Se pretende que se inicialize todo lo necesario para empezar a dibujar los componentes 
		necesarios de la aplicaci�n. 
		
		No se deben confundir tareas de constructor puesto que ac� solo se inicializa lo referente 
		a tareas gr�ficas.
	*/
	void setup();

	/// Controla tareas l�gica de cada ciclo de OpenGL
	/**
		En cada ciclo de OpenGL este m�todo se llama antes de draw() para actualizar las tareas
		l�gicas de la interfaz gr�fica. 

		Se puede ver esta instancia como un m�todo padre porque invoca al update del espacio que
		est� activo al momento de ejecuci�n.
	*/
	void update();

	/// Controla las tareas gr�ficas de cada ciclo de OpenGL
	/**
		Aqu� se realizan todas la tareas de dibujar elementos en pantalla. Este m�todo dibuja la 
		representaci�n de la entrada (ya sea por pupilas o por gestos). Adem�s se encarga de llamar
		al draw() del espacio activo.

		La forma en la que se dibuja en la pantalla es por orden de llamados. Las cosas que se 
		llamen a dibujar de primero van a quedar "al fondo".
	*/
	void draw();

	/// Se activa cada vez que el usuario presiona una tecla
	void keyPressed(int key);

	/// Se activa cada vez que el usuario suelta una tecla
	void keyReleased(int key);

	/// Se activa cuando el mouse se mueve de posici�n
	void mouseMoved(int x, int y);

	/// Se activa cuando el usuario arrastra el mouse dejando cierto bot�n apretado
	void mouseDragged(int x, int y, int button);

	/// Se activa cuando el usuario presiona un bot�n del mouse
	void mousePressed(int x, int y, int button);

	/// Se activa cuando el usuario suelta un bot�n del mouse
	void mouseReleased(int x, int y, int button);

	/// Se activa cuando la ventana cambia de tama�o
	void windowResized(int w, int h);

	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:

	/// Define el modo de entrada 
	Modo modo;

	/// Controlador de la ventana
	HWND hwndWindow;

	/// Controlador del Tobii EyeX
	EyeXHost *host;

	/// Controlador del Leap Motion
	LeapHost *leapHost;

	/// Instancia del espacio activo en la pantalla.
	/**
		Este puntero se mueve din�micamente. Si un espacio necesita cambiar a otro solo necesita
		modificar el puntero hacia el espacio que se quiere activar y el ciclo de OpenGL se encarga
		de invocar a sus debidos m�todos.

		Si el puntero llega alguna vez a ser 0 representa la salida del programa.
	*/
	espacioBase   *espacioActivo;

	/// Instancia del men� principal de la aplicaci�n
	menuPrincipal *mPrincipal;
	
	/// Tama�o en el eje X de la pantalla de la aplicaci�n
	int tamX;

	/// Tama�o en el eje Y de la pantalla de la aplicaci�n
	int tamY;
	
	/// Radio del circulo que
	const int radioMirada = 30;

	/// Ultima posicion del usuario en el eye x registrada
	int ultimoX;

	/// Ultima posicion del usuario en el eye y registrada
	int ultimoY;

	/// Utilidad que calcula la distancia entre dos circulos
	double circleDistance(double, double, double, double);

};

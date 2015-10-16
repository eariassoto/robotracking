#pragma once
#include "ofMain.h"
#include "espacioBase.h"
#include "menuPrincipal.h"
#include "LeapHost.h"
#include "EyeXHost.h"

/// Clase base que coordina la interacción entre el ciclo de OpenGL y la aplicación como tal
/**
	Esta clase se maneja por medio de los eventos establecidos por OpenGL. Cualquier espacio 
	de la aplicacion debe tener al menos implementado los métodos setup(), update() y draw() 
	para que puedan ser inicializados y dibujados en pantalla. Las demás funciones de OpenGL 
	se definen pero se dejan vacías.
*/
class ofApp : public ofBaseApp
{

public:

	enum class Modo{ Tobii, Leap, Mouse };

	/// Constructor de la clase
	/**
		Por defecto, inicia la aplicación en modo visión, sin embargo puede definirse un 
		parámetro de constructor para definir el modo desde el main o leerlo desde un archivo
		de configuración.

		\param m modo de entrada para la instancia de la aplicación
		\param[in] x tamaño del largo de la ventana de la aplicación
		\param[in] y tamaño del ancho de la ventana de la apliación
		\param _hwndWindow manejador de la ventana principal
	*/
	ofApp(Modo, int, int, HWND);

	/// Destructor de la clase
	/**
		Borra a mPrincipal
	*/
	~ofApp();

	/// Método inicial del ciclo de OpenGL
	/**
		Se pretende que se inicialize todo lo necesario para empezar a dibujar los componentes 
		necesarios de la aplicación. 
		
		No se deben confundir tareas de constructor puesto que acá solo se inicializa lo referente 
		a tareas gráficas.
	*/
	void setup();

	/// Controla tareas lógica de cada ciclo de OpenGL
	/**
		En cada ciclo de OpenGL este método se llama antes de draw() para actualizar las tareas
		lógicas de la interfaz gráfica. 

		Se puede ver esta instancia como un método padre porque invoca al update del espacio que
		está activo al momento de ejecución.
	*/
	void update();

	/// Controla las tareas gráficas de cada ciclo de OpenGL
	/**
		Aquí se realizan todas la tareas de dibujar elementos en pantalla. Este método dibuja la 
		representación de la entrada (ya sea por pupilas o por gestos). Además se encarga de llamar
		al draw() del espacio activo.

		La forma en la que se dibuja en la pantalla es por orden de llamados. Las cosas que se 
		llamen a dibujar de primero van a quedar "al fondo".
	*/
	void draw();

	/// Se activa cada vez que el usuario presiona una tecla
	void keyPressed(int key);

	/// Se activa cada vez que el usuario suelta una tecla
	void keyReleased(int key);

	/// Se activa cuando el mouse se mueve de posición
	void mouseMoved(int x, int y);

	/// Se activa cuando el usuario arrastra el mouse dejando cierto botón apretado
	void mouseDragged(int x, int y, int button);

	/// Se activa cuando el usuario presiona un botón del mouse
	void mousePressed(int x, int y, int button);

	/// Se activa cuando el usuario suelta un botón del mouse
	void mouseReleased(int x, int y, int button);

	/// Se activa cuando la ventana cambia de tamaño
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
		Este puntero se mueve dinámicamente. Si un espacio necesita cambiar a otro solo necesita
		modificar el puntero hacia el espacio que se quiere activar y el ciclo de OpenGL se encarga
		de invocar a sus debidos métodos.

		Si el puntero llega alguna vez a ser 0 representa la salida del programa.
	*/
	espacioBase   *espacioActivo;

	/// Instancia del menú principal de la aplicación
	menuPrincipal *mPrincipal;
	
	/// Tamaño en el eje X de la pantalla de la aplicación
	int tamX;

	/// Tamaño en el eje Y de la pantalla de la aplicación
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

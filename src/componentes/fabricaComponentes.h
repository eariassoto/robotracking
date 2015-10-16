#pragma once
#include "componenteBase.h"
#include "botonSimple.h"
#include "cajaTexto.h"
#include "ofColor.h"
#include "ofxXmlSettings.h"
#include <stdio.h>
#include <vector>

using namespace std;

/// Utilidad para generar componentes a partir de archivos de configuración
/**
	A veces es útil tener archivos de configuración para los espacios que contengan los elementos y sus
	atributos definidos para la interfaz y que sean cargados al inicio que definirlos en la misma clase.
*/
class fabricaComponentes
{

public:

	/// Constructor de la clase
	fabricaComponentes() {};

	/// Genera una lista de componentes a partir de un archivo de configuración
	/**
		Dado un archivo de configuración se crean las instancias de componentes y se almacenan en una lista.

		\param conf Instancia de manejador de archivos de configuración
		\param parentTag Etiqueta XML la cual contiene la lista de componentes
		\return Lista de componentes
	*/
	vector<componenteBase*> obtenerComponentes(ofxXmlSettings &conf, string parentTag)
	{
		conf.pushTag(parentTag);
		vector<componenteBase*> v;

		int n = conf.getNumTags("boton");
		if (n > 0)
		{
			for (int i = 0; i<n; i++)
			{
				conf.pushTag("boton", i);
				if (conf.getValue("id", "") == "caracter")
				{
					int x = conf.getValue("x", 0);
					int y = conf.getValue("y", 0);
					int w = conf.getValue("width", 0);
					int h = conf.getValue("height", 0);
					conf.pushTag("texto", 0);
					int f = conf.getValue("tamano", 0);
					conf.pushTag("color", 0);
					ofColor c(conf.getValue("r", 0), conf.getValue("g", 0), conf.getValue("b", 0));
					conf.popTag();
					string t = conf.getValue("hilera", "");
					conf.popTag();
					v.push_back(new botonSimple(t, f, c, x, y, w, h, 192));
				}
				conf.popTag();
			}
		}
		conf.popTag();
		return v;
	};

	/// Busca y crea una caja de texto definida en el archivo de configuración
	/**
		A como está implementado se espera que exista solo una caja de texto.

		\param conf Instancia de manejador de archivos de configuración	
		\return Instancia de la caja de texto
	*/
	cajaTexto* obtenerCajaTexto(ofxXmlSettings &conf)
	{
		cajaTexto *cT;
		conf.pushTag("espacio");
		int n = conf.getNumTags("cajaTexto");
		if (n == 1)
		{

			conf.pushTag("cajaTexto", 0);
			int x = conf.getValue("x", 0);
			int y = conf.getValue("y", 0);
			int w = conf.getValue("width", 0);
			int h = conf.getValue("height", 0);
			conf.pushTag("texto", 0);
			int f = conf.getValue("tamano", 0);
			ofColor c(conf.getValue("r", 0), conf.getValue("g", 0), conf.getValue("b", 0));
			conf.popTag();
			cT = new cajaTexto(f, c, x, y, w, h);
			conf.popTag();

		}
		conf.popTag();

		return cT;
	}

	/// Busca y crea un botón que tenga un cierto identificador
	/**
		\param id Identificador del botón
		\param conf Instancia de manejador de archivos de configuración
		\return Instancia de la caja de texto
	*/
	botonSimple* obtenerBotonId(string id, ofxXmlSettings &conf)
	{
		botonSimple* b = 0;
		conf.pushTag("espacio");
		int n = conf.getNumTags("boton");
		if (n > 0)
		{
			for (int i = 0; i<n; i++)
			{
				conf.pushTag("boton", i);
				if (conf.getValue("id", "") == id)
				{
					int x = conf.getValue("x", 0);
					int y = conf.getValue("y", 0);
					int w = conf.getValue("width", 0);
					int h = conf.getValue("height", 0);
					conf.pushTag("texto", 0);
					int f = conf.getValue("tamano", 0);
					ofColor c(conf.getValue("r", 0), conf.getValue("g", 0), conf.getValue("b", 0));
					string t = conf.getValue("hilera", "");
					conf.popTag();
					b = new botonSimple(t, f, c, x, y, w, h);
				}
				conf.popTag();
			}
		}
		conf.popTag();
		return b;
	}
};


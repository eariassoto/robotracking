#include "menuBase.h"
#include "ofGraphics.h"

using namespace std;

menuBase::menuBase(string confPath, espacioBase *espPadre) : espacioBase(espPadre){
	configuraciones.loadFile(confPath);
}

void menuBase::setup(){
	fuente.loadFont("opensansfont.ttf", 34);
	
	configuraciones.pushTag("menu");

	logo.loadImage("logo2.jpg");
	float escala = .7;
	logo.resize(logo.getWidth()*escala, logo.getHeight()*escala);

	int cantBtn = configuraciones.getNumTags("botonImagen");
	int tamBtn = configuraciones.getValue("tamBoton", 0);
	int yBtn = configuraciones.getValue("yBoton", 0);

	logox = (1280 - logo.getWidth()) / 2;
	logoy = 720 * 0.025f;

	int cantMargenes = 4 + (cantBtn - 1);
	int margen = (int)((1280 - (tamBtn * cantBtn)) / cantMargenes);

	for (int i = 0; i < cantBtn; i++)
	{
		configuraciones.pushTag("botonImagen", i);
		string ruta = configuraciones.getValue("ruta", "");
		float escala = configuraciones.getValue("escala", 0.0f);

		configuraciones.pushTag("texto");
		string texto = configuraciones.getValue("hilera", "");
		int tamFuente = configuraciones.getValue("tamano", 0);

		configuraciones.pushTag("color", 0);
		ofColor c(configuraciones.getValue("r", 0), configuraciones.getValue("g", 0), configuraciones.getValue("b", 0));
		configuraciones.popTag();

		configuraciones.popTag();

		int x = ((2 + i) * margen) + (i*tamBtn);
		int y = yBtn;
		int w = tamBtn;
		int h = tamBtn;

		btn.push_back(botonImagen(ruta, escala, texto, tamFuente, c, x, y, w, h));

		configuraciones.popTag();
	}

	btnAtras = new botonImagen("img/mComunicacion/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);
}

espacioBase* menuBase::update(float x, float y, float xL, float yL, bool clic){
	espacioBase* r = this;

	int i = 0;
	for (vector<botonImagen>::iterator it = btn.begin(); it != btn.end(); it++)
	{
		if ((*it).update(x, y, xL, yL, clic)){
			r = eventos(i);
		}
		i++;
	}

	if (btnAtras->update(x, y, xL, yL, clic))
	{
		r = eventos(-1);
	}

	return r;

}

void menuBase::draw()
{
	//ofSetColor(200,125,26);
	ofSetColor(255, 255, 255);

	logo.draw(logox, logoy);

	for (vector<botonImagen>::iterator it = btn.begin(); it != btn.end(); it++)
	{
		(*it).draw();
	}

	btnAtras->draw();
}

menuBase::~menuBase(){

	delete btnAtras;
}

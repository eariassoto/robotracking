#include <stdlib.h> 
#include "espacioTarjetas.h"

espacioTarjetas::espacioTarjetas(espacioBase* espPadre) :espacioBase(espPadre){


}

void espacioTarjetas::setup()
{

	correcto = false;
	incorrecto = false;

	baseDatos = new sqlite3Manager("data/db/robotracking.db3");
	tarjetas = baseDatos->executeStatement("SELECT * FROM Categoria");

	fuenteResp.loadFont("opensansfont.ttf", 72);
	fuenteResp2.loadFont("opensansfont.ttf", 28);
	fuenteResp3.loadFont("opensansfont.ttf", 48);

	srand(time(NULL));

	btn0 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 10, 450, 80);
	btn1 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 100, 450, 80);
	btn2 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 190, 450, 80);
	btn3 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 280, 450, 80);
	btnNuevo = new botonSimple("Nueva imagen", 34, ofColor(0, 0, 0), 540, 500, 450, 80);
	btnAtras = new botonImagen("img/mComunicacion/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);

	cargarTarjeta();
}

void espacioTarjetas::cargarTarjeta(){
	resp.clear();
	int s = tarjetas.size();
	int tmp = rand() % s;
	resp.push_back(tmp);

	do
	{
		tmp = rand() % s;
	} while (tmp == resp[0]);
	resp.push_back(tmp);

	do
	{
		tmp = rand() % s;
	} while (tmp == resp[0] || tmp == resp[1]);
	resp.push_back(tmp);

	do
	{
		tmp = rand() % s;
	} while (tmp == resp[0] || tmp == resp[1] || tmp == resp[2]);
	resp.push_back(tmp);

	img.loadImage(tarjetas[resp[0]][1]);

	int data[] = { 0, 1, 2, 3 };
	random_shuffle(data, data + 4);

	btn0->setTexto(tarjetas[resp[data[0]]][0]);
	btn1->setTexto(tarjetas[resp[data[1]]][0]);
	btn2->setTexto(tarjetas[resp[data[2]]][0]);
	btn3->setTexto(tarjetas[resp[data[3]]][0]);
}

void espacioTarjetas::validarRespuesta(botonSimple *btn){
	if ((tarjetas[resp[0]][0] == btn->getTexto()))
	{
		correcto = true;
		incorrecto = false;
	}
	else
	{
		incorrecto = true;
		correcto = false;
	}
}

espacioBase* espacioTarjetas::update(float x, float y, float xL, float yL, bool clic)
{
	espacioBase* r = this;
	if (btnAtras->update(x, y, xL, yL, clic))
	{
		r = espacioPadre;
	}

	if (btn0->update(x, y, xL, yL, clic))
	{
		validarRespuesta(btn0);
	}
	if (btn1->update(x, y, xL, yL, clic))
	{
		validarRespuesta(btn1);
	}
	if (btn2->update(x, y, xL, yL, clic))
	{
		validarRespuesta(btn2);
	}
	if (btn3->update(x, y, xL, yL, clic))
	{
		validarRespuesta(btn3);
	}
	if ((correcto || incorrecto) && btnNuevo->update(x, y, xL, yL, clic))
	{
		cargarTarjeta();
		correcto = incorrecto = false;
	}
	return r;

}

void espacioTarjetas::draw()
{
	btnAtras->draw();
	btn0->draw();
	btn1->draw();
	btn2->draw();
	btn3->draw();

	ofSetColor(126, 126, 126);
	ofRect(10, 10, 520, 520);

	ofSetColor(255, 255, 255);
	img.draw(20, 20);

	if (correcto)
	{
		ofSetColor(35, 232, 51);
		fuenteResp.drawString("Correcto", 540, 440);

		ofSetColor(0, 0, 0);
		fuenteResp2.drawString("Muy bien", 540, 480);

		btnNuevo->draw();
	}

	if(incorrecto)
	{
		ofSetColor(255, 33, 23);
		fuenteResp3.drawString("Vuelve a intentarlo", 540, 440);
	}
	
}

espacioTarjetas::~espacioTarjetas(){
	delete btnAtras;
	delete btn0;
	delete btn1;
	delete btn2;
	delete btn3;
	delete baseDatos;
}

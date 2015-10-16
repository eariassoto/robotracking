#include <stdlib.h> 
#include "espacioTarjetas.h"

espacioTarjetas::espacioTarjetas(espacioBase* espPadre) :espacioBase(espPadre){


}

void espacioTarjetas::setup()
{

	correcto = false;
	incorrecto = false;

	baseDatos = new sqlite3Manager("data/db/robotracking.db3");
	tarjetas = baseDatos->executeStatement("SELECT * FROM pictograma WHERE NombreCat='Sustantivos'");

	fuenteResp.loadFont("opensansfont.ttf", 72);
	fuenteResp2.loadFont("opensansfont.ttf", 28);
	fuenteResp3.loadFont("opensansfont.ttf", 48);

	srand(time(NULL));

	btn0 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 10, 450, 80);
	btn1 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 100, 450, 80);
	btn2 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 190, 450, 80);
	btn3 = new botonSimple("", 34, ofColor(0, 0, 0), 540, 280, 450, 80);
	btnNuevo = new botonSimple("Nueva imagen", 34, ofColor(0, 0, 0), 540, 480, 450, 80);
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

	img.loadImage(tarjetas[resp[0]][2]);

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

espacioBase* espacioTarjetas::update(bool btnAtrasRes, bool btn0Res, bool btn1Res, bool btn2Res, 
	bool btn3Res, bool btnNuevoRes)
{
	espacioBase* r = this;
	if (btnAtrasRes)
	{
		r = espacioPadre;
	}
	if (btn0Res)
	{
		validarRespuesta(btn0);
	}
	if (btn1Res)
	{
		validarRespuesta(btn1);
	}
	if (btn2Res)
	{
		validarRespuesta(btn2);
	}
	if (btn3Res)
	{
		validarRespuesta(btn3);
	}
	if ((correcto || incorrecto) && btnNuevoRes)
	{
		cargarTarjeta();
		correcto = incorrecto = false;
	}
	return r;
}

espacioBase* espacioTarjetas::update(float x, float y)
{
	bool btnAtrasRes = btnAtras->update(x, y);
	bool btn0Res = btn0->update(x, y);
	bool btn1Res = btn1->update(x, y);
	bool btn2Res = btn2->update(x, y);
	bool btn3Res = btn3->update(x, y);
	bool btnNuevoRes = btnNuevo->update(x, y);

	return update(btnAtrasRes, btn0Res, btn1Res, btn2Res, btn3Res, btnNuevoRes);

}

espacioBase* espacioTarjetas::update(float x, float y, bool clic)
{
	bool btnAtrasRes = btnAtras->update(x, y, clic);
	bool btn0Res = btn0->update(x, y, clic);
	bool btn1Res = btn1->update(x, y, clic);
	bool btn2Res = btn2->update(x, y, clic);
	bool btn3Res = btn3->update(x, y, clic);
	bool btnNuevoRes = btnNuevo->update(x, y, clic);

	return update(btnAtrasRes, btn0Res, btn1Res, btn2Res, btn3Res, btnNuevoRes);

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

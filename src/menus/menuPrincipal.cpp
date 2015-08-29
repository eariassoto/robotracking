#include "menuPrincipal.h"
#include "ofGraphics.h"


menuPrincipal::menuPrincipal(bool vM) : espacioBase(0){
	visionMode = vM;
}

void menuPrincipal::setup(){
	fuente.loadFont("opensansfont.ttf", 34);

	logo.loadImage("logo2.jpg");
	float escala = .7;
	logo.resize(logo.getWidth()*escala, logo.getHeight()*escala);

	logox = (1280 - logo.getWidth()) / 2;
	logoy = 720 * 0.025f;

	int btnTam = 300;
	int margen = (int)((1280 - (btnTam * 4)) / 7);

	int btny = 230;

	btnComunicacion = new botonImagen("img/principal/comunicacion.png", 0.725f, "Comunicacion", 24, ofColor(0, 0, 0), (2 * margen), btny, btnTam, btnTam);
	btnEducacion = new botonImagen("img/principal/educacion.png", 0.725f, "Educacion", 24, ofColor(0, 0, 0), (3 * margen) + btnTam, btny, btnTam, btnTam);
	btnCotidiana = new botonImagen("img/principal/cotidiana.png", 0.725f, "Vida cotidiana", 24, ofColor(0, 0, 0), (5 * margen) + (3 * btnTam), btny, btnTam, btnTam);
	btnOcio = new botonImagen("img/principal/ocio.png", 0.725f, "Ocio", 24, ofColor(0, 0, 0), (4 * margen) + (2 * btnTam), btny, btnTam, btnTam);
	btnSalir = new botonImagen("img/principal/x.png", 0.5f, "Salir", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);

	if (visionMode)
		btnInput = new botonToggle("img/principal/ojo.png", "img/principal/leap.png", 0.5f, "Vision", "Gestos", 24, ofColor(0, 0, 0), 10, 580, 125, 125);
	else
		btnInput = new botonToggle("img/principal/leap.png", "img/principal/ojo.png", 0.5f, "Gestos", "Vision", 24, ofColor(0, 0, 0), 10, 580, 125, 125);

	mComunicacion = new menuComunicacion(this);
	mOcio = new menuOcio(this);
	mEducacion = new menuEducacion(this);
	mCotidiana = new menuCotidiana(this);
	mComunicacion->setup();
	mOcio->setup();
	mEducacion->setup();
	mCotidiana->setup();
}

espacioBase* menuPrincipal::update(float x, float y, float xL, float yL, bool clic){
	espacioBase *r = this;
	
	if (btnComunicacion->update(x, y, xL, yL, clic))
	{
		r = mComunicacion;
	}
	if (btnEducacion->update(x, y, xL, yL, clic))
	{
		r = mEducacion;
	}
	if (btnCotidiana->update(x, y, xL, yL, clic))
	{
		r = mCotidiana;
	}
	if (btnOcio->update(x, y, xL, yL, clic))
	{
		r = mOcio;
	}
	if (btnSalir->update(x, y, xL, yL, clic))
	{
		r = 0;
	}

	if (btnInput->update(x, y, xL, yL, clic)){
		visionMode = !visionMode;
	}
	return r;

}

void menuPrincipal::draw()
{
	//ofSetColor(200,125,26);
	ofSetColor(255, 255, 255);

	logo.draw(logox, logoy);

	btnComunicacion->draw();
	btnEducacion->draw();
	btnCotidiana->draw();
	btnOcio->draw();
	btnSalir->draw();
	btnInput->draw();
}

menuPrincipal::~menuPrincipal(){
	delete btnComunicacion;
	delete btnEducacion;
	delete btnCotidiana;
	delete btnOcio;
	delete btnSalir;
	delete mComunicacion;
	delete mCotidiana;
	delete mOcio;
	delete mEducacion;
	delete btnInput;
}

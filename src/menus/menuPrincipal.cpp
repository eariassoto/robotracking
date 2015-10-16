#include "menuPrincipal.h"
#include "ofGraphics.h"


menuPrincipal::menuPrincipal() : espacioBase(0){
	//visionMode = vM;
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

	if (true) // TODO
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

espacioBase* menuPrincipal::update(bool btnComunicacionRes, bool btnEducacionRes, bool btnCotidianaRes,
	bool btnOcioRes, bool btnSalirRes, bool btnInputRes)
{
	espacioBase *r = this;

	if (btnComunicacionRes)
	{
		r = mComunicacion;
	}
	if (btnEducacionRes)
	{
		r = mEducacion;
	}
	if (btnCotidianaRes)
	{
		r = mCotidiana;
	}
	if (btnOcioRes)
	{
		r = mOcio;
	}
	if (btnSalirRes)
	{
		r = 0;
	}

	if (btnInputRes){
		//visionMode = !visionMode;
	}
	return r;
}

espacioBase* menuPrincipal::update(float x, float y, bool clic){

	bool btnComunicacionRes = btnComunicacion->update(x, y,clic);
	bool btnEducacionRes = btnEducacion->update(x, y, clic);
	bool btnCotidianaRes = btnCotidiana->update(x, y, clic);
	bool btnOcioRes = btnOcio->update(x, y, clic);
	bool btnSalirRes = btnSalir->update(x, y, clic);
	bool btnInputRes = btnInput->update(x, y, clic);
	
	return update(btnComunicacionRes, btnEducacionRes, btnCotidianaRes, btnOcioRes, btnSalirRes, btnInputRes);
	
}

espacioBase* menuPrincipal::update(float x, float y){

	bool btnComunicacionRes = btnComunicacion->update(x, y);
	bool btnEducacionRes = btnEducacion->update(x, y);
	bool btnCotidianaRes = btnCotidiana->update(x, y);
	bool btnOcioRes = btnOcio->update(x, y);
	bool btnSalirRes = btnSalir->update(x, y);
	bool btnInputRes = btnInput->update(x, y);

	return update(btnComunicacionRes, btnEducacionRes, btnCotidianaRes, btnOcioRes, btnSalirRes, btnInputRes);

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

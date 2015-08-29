#include "espacioCamara.h"

espacioCamara::espacioCamara(espacioBase* espPadre) :espacioBase(espPadre){


}

void espacioCamara::setup()
{

	camWidth = 800;
	camHeight = 600;
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth, camHeight);
	img.allocate(camWidth, camHeight, OF_IMAGE_COLOR);

	camX = (1230 - 800) / 2;
	camY = 10;

	btnFoto = new botonImagen("img/eFotos/camara.png", 0.725f, "Tomar Foto", 14, ofColor(0, 0, 0), 1010, 20, 200, 200);
	btnGaleria = new botonImagen("img/eFotos/galeria.png", 0.725f, "Ver Fotos", 14, ofColor(0, 0, 0), 1010, 260, 200, 200);
	btnAtras = new botonImagen("img/mComunicacion/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);
}

espacioBase* espacioCamara::update(float x, float y, float xL, float yL, bool clic)
{
	espacioBase* r = this;

	if (btnAtras->update(x, y, xL, yL, clic))
	{
		r = espacioPadre;
	}

	btnGaleria->update(x, y, xL, yL, clic);
	
	bool estadoFoto = btnFoto->update(x, y, xL, yL, clic);
	if (estadoFoto)
	{
		auto t = time(nullptr);
		auto tm = *localtime(&t);

		stringstream buffer;
		buffer << put_time(&tm, "%d%m%Y-%H%M%S");
		string r = "fotos/img" + buffer.str() + ".png";
		
		img.saveImage(r);
		//id++;

	}
	
	vidGrabber.update();
	if (vidGrabber.isFrameNew())
	{
		img.setFromPixels(vidGrabber.getPixelsRef());
	}

	return r;

}

void espacioCamara::draw()
{
	btnAtras->draw();
	btnFoto->draw();
	btnGaleria->draw();
	ofSetColor(255, 255, 255);
	vidGrabber.draw(camX, camY);
}

espacioCamara::~espacioCamara(){
	delete btnAtras;
	delete btnFoto;
	delete btnGaleria;
}

#include "espacioTeclado.h"

espacioTeclado::espacioTeclado(string confPath, espacioBase* espPadre) :espacioBase(espPadre)
{
	configuraciones.loadFile(confPath);
}

void espacioTeclado::setup(){
	
	componentes = fabComponentes.obtenerComponentes(configuraciones, "espacio");
	cantidadComponentes = componentes.size();

	cTexto = fabComponentes.obtenerCajaTexto(configuraciones);
	btnBorrar = fabComponentes.obtenerBotonId("borrar", configuraciones);
	btnEspacio = fabComponentes.obtenerBotonId("espacio", configuraciones);
	btnHablar = fabComponentes.obtenerBotonId("hablar", configuraciones);

	btnSalir = new botonImagen("img/principal/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);

}

void espacioTeclado::comandoHablar(string s){

	string cmd = "-v es-la \"" + s + "\"";
	ShellExecute(NULL, "open", "C:\\Program Files (x86)\\eSpeak\\command_line\\espeak.exe", cmd.c_str(), NULL, SW_HIDE);

}

espacioBase* espacioTeclado::update(float x, float y, float xL, float yL, bool clic)
{
	espacioBase *r = this;
	bool estado;

	for (int i = 0; i != cantidadComponentes; i++)
	{
		estado = componentes[i]->update(x, y, xL, yL, clic);
		if (estado)
		{
			botonSimple* btn = dynamic_cast<botonSimple*>(componentes[i]);
			cTexto->appendTexto(btn->getTexto());
		}

	}
	cTexto->update(x, y, xL, yL, clic);

	if (btnBorrar->update(x, y, xL, yL, clic))
	{
		cTexto->borrarCaracter();
	}
	if (btnEspacio->update(x, y, xL, yL, clic))
	{
		cTexto->appendTexto(" ");
	}
	if (btnHablar->update(x, y, xL, yL, clic))
	{
		comandoHablar(cTexto->getTexto());
	}
	if (btnSalir->update(x, y, xL, yL, clic))
	{
		r = espacioPadre;
	}

	return r;
}

void espacioTeclado::draw()
{

	for (int i = 0; i != cantidadComponentes; i++)
	{
		componentes[i]->draw();
	}
	cTexto->draw();
	btnBorrar->draw();
	btnEspacio->draw();
	btnHablar->draw();
	btnSalir->draw();
}

espacioTeclado::~espacioTeclado(){
	delete cTexto;
	delete btnBorrar;
	delete btnEspacio;
	delete btnHablar;
	delete btnSalir;
}

#include "espacioTeclado.h"

espacioTeclado::espacioTeclado(string confPath, espacioBase* espacioPadre) :espacioBase(espacioPadre)
{
	configuraciones.loadFile(confPath);
}

void espacioTeclado::setup(){
	
	componentes = fabComponentes.obtenerComponentes(configuraciones, "espacio");
	cantidadComponentes = componentes.size();

	cTexto = fabComponentes.obtenerCajaTexto(configuraciones);
	cTexto->appendTexto("abc");

	btnBorrar = fabComponentes.obtenerBotonId("borrar", configuraciones);
	btnLimpiar = fabComponentes.obtenerBotonId("limpiar", configuraciones);
	btnEspacio = fabComponentes.obtenerBotonId("espacio", configuraciones);
	btnHablar = fabComponentes.obtenerBotonId("hablar", configuraciones);

	btnSalir = new botonImagen("img/principal/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);

	tooltip = new cajaTexto(36, ofColor(0, 0, 0), 20, 290, 110, 50, 128);
	tooltip->appendTexto("abc");
}

void espacioTeclado::comandoHablar(string s){

	string cmd = "-v es-la \"" + s + "\"";
	ShellExecute(NULL, "open", "C:\\Program Files (x86)\\eSpeak\\command_line\\espeak.exe", cmd.c_str(), NULL, SW_HIDE);

}


espacioBase* espacioTeclado::update(bool btnBorrarRes, bool btnEspacioRes, 
	bool btnHablarRes, bool btnSalirRes, bool btnLimpiarRes)
{
	espacioBase *r = this;
	bool estado;

	for (int i = 0; i != cantidadComponentes; i++)
	{
		if (componentes[i]->seHizoClic())
		{
			botonSimple* btn = dynamic_cast<botonSimple*>(componentes[i]);
			cTexto->appendTexto(btn->getTexto());
			tooltip->appendTexto(btn->getTexto());
		}

	}
	if (btnLimpiarRes)
	{
		cTexto->limpiar();
		tooltip->limpiar();
	}
	if (btnBorrarRes)
	{
		cTexto->borrarCaracter();
		tooltip->borrarCaracter();
	}
	if (btnEspacioRes)
	{
		cTexto->appendTexto(" ");
		tooltip->limpiar();
	}
	if (btnHablarRes)
	{
		comandoHablar(cTexto->getTexto());
	}
	if (btnSalirRes)
	{
		r = espacioPadre;
	}

	return r;
}

espacioBase* espacioTeclado::update(float x, float y, bool clic)
{
	bool btnBorrarRes = btnBorrar->update(x, y, clic);
	bool btnEspacioRes = btnEspacio->update(x, y, clic);
	bool btnHablarRes = btnHablar->update(x, y, clic);
	bool btnSalirRes = btnSalir->update(x, y, clic);
	bool btnLimpiarRes = btnLimpiar->update(x, y, clic);
	

	for (int i = 0; i != cantidadComponentes; i++)
	{
		componentes[i]->update(x, y, clic);
	}
	
	return update(btnBorrarRes, btnEspacioRes, btnHablarRes, btnSalirRes, btnLimpiarRes);
}

espacioBase* espacioTeclado::update(float x, float y)
{
	bool btnBorrarRes = btnBorrar->update(x, y);
	bool btnEspacioRes = btnEspacio->update(x, y);
	bool btnHablarRes = btnHablar->update(x, y);
	bool btnSalirRes = btnSalir->update(x, y);
	bool btnLimpiarRes = btnLimpiar->update(x, y);


	for (int i = 0; i != cantidadComponentes; i++)
	{
		componentes[i]->update(x, y);
	}

	return update(btnBorrarRes, btnEspacioRes, btnHablarRes, btnSalirRes, btnLimpiarRes);
}


void espacioTeclado::draw()
{
	cTexto->draw();
	int tooltipX = 0, tooltipY = 0;

	for (int i = 0; i != cantidadComponentes; i++)
	{
		if (componentes[i]->hayMouseEncima())
		{
			tooltipX = componentes[i]->x;
			tooltipY = componentes[i]->y - 50;
		}
		componentes[i]->draw();
	}
	btnBorrar->draw();
	btnEspacio->draw();
	btnHablar->draw();
	btnSalir->draw();
	btnLimpiar->draw();

	if (tooltipX)
	{
		tooltip->x = tooltipX;
		tooltip->y = tooltipY;
		tooltip->draw();
	}
	
}

espacioTeclado::~espacioTeclado(){
	delete cTexto;
	delete btnBorrar;
	delete btnEspacio;
	delete btnHablar;
	delete btnSalir;
	delete btnLimpiar;
	delete tooltip;
}

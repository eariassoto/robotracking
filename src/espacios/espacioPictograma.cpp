#include "espacioPictograma.h"

espacioPictograma::espacioPictograma(espacioBase* espPadre) :espacioBase(espPadre){

	// inicia en la primera categoria
	categoriaActual = 0;

	baseDatos = new sqlite3Manager("data/db/robotracking.db3");

	strCategorias = baseDatos->executeStatement("SELECT * FROM Categoria");

	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Acciones'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Cortesia'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Descripcion'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Emociones'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Frases'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Otros'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Personas'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Preguntas'"));
	strPictogramas.push_back(baseDatos->executeStatement("SELECT Descripcion, Icono FROM Pictograma WHERE NombreCat = 'Sustantivos'"));

}

espacioPictograma::~espacioPictograma()
{
	delete btnAdelante;
	delete btnAtras;
	delete btnHablar;
	delete btnBorrar;
	delete btnBorrarTodo;
	delete btnSalir;
	delete baseDatos;
}

void espacioPictograma::setup()
{
	
	indice = 0;
	tam = 120;
	margen = (720 - (5 * tam)) / 6;

	for (int i = 0; i < strCategorias.size(); i++)
	{
		string nombre = strCategorias.at(i)[0];
		string ruta = strCategorias.at(i)[1];
		int x = 20;
		int y = (i + 1)*margen + i*tam;
		if (i > 4){
			x = 40 + tam;
			y -= (5 * margen) + (5*tam);
		}
		
		btnCategorias.push_back(botonImagen(ruta, 0.725f, nombre, 12, ofColor(0, 0, 0), x, y, tam, tam));
	}

	btnAtras = new botonImagen("img/ePictograma/atras.png", 0.6f, "Atras", 14, ofColor(0, 0, 0), 320, 395, 100, 100);
	btnAdelante = new botonImagen("img/ePictograma/adelante.png", 0.6f, "Adelante", 14, ofColor(0, 0, 0), 975, 395, 100, 100);
	btnBorrar = new botonImagen("img/ePictograma/ultimo.png", 0.725f, "Borrar ultimo", 14, ofColor(0, 0, 0), 1115, 20, 150, 150);
	btnBorrarTodo = new botonImagen("img/ePictograma/todo.png", 0.725f, "Borrar todo", 14, ofColor(0, 0, 0), 1115, 200, 150, 150);
	btnHablar = new botonImagen("img/ePictograma/altavoz.png", 0.725f, "Hablar", 14, ofColor(0, 0, 0), 1115, 380, 150, 150);
	btnSalir = new botonImagen("img/principal/x.png", 0.5f, "Atras", 24, ofColor(0, 0, 0), 1140, 580, 125, 125);

	tam = 240;
	margen = 25;
	offsetX = 445;
	offsetY = 190;

	int size = getTamPictograma();
	btnAdelanteVisible = size > 4;
	btnAtrasVisible = false;
	cargarPictogramas();
	
}
espacioBase* espacioPictograma::update(bool btnSalirRes, bool btnAtrasRes, bool btnAdelanteRes, 
	bool btnHablarRes, bool btnBorrarRes, bool btnBorrarTodoRes)
{
	espacioBase* r = this;
	if (btnSalirRes)
	{
		r = espacioPadre;
	}

	if (btnAtrasVisible && btnAtrasRes){
		int size = getTamPictograma();
		indice -= 4;

		if (indice <= 0)
			btnAtrasVisible = false;

		if (indice + 4 < (size - 1))
			btnAdelanteVisible = true;

		cargarPictogramas();
	}

	if (btnAdelanteVisible && btnAdelanteRes){
		int size = getTamPictograma();
		indice += 4;
		btnAtrasVisible = true;
		if (indice + 4 > (size - 1))
			btnAdelanteVisible = false;

		cargarPictogramas();

	}

	if (btnHablarRes){
		string texto = "";
		for (vector<pair<string, ofImage>>::iterator it = pictogramasActuales.begin(); it != pictogramasActuales.end(); it++){
			texto += (*it).first + " ";
		}
		comandoHablar(texto);
	}

	if (btnBorrarRes){
		if (!pictogramasActuales.empty())
			pictogramasActuales.pop_back();
	}

	if (btnBorrarTodoRes){
		pictogramasActuales.clear();
	}

	int i = 0;
	for (vector<botonImagen>::iterator it = btnCategorias.begin(); it != btnCategorias.end(); it++){
		if ((*it).seHizoClic()){
			categoriaActual = i;
			indice = 0;
			btnAtrasVisible = false;
			int size = getTamPictograma();
			if (indice + 4 < (size - 1))
				btnAdelanteVisible = true;
			cargarPictogramas();
		}
		i++;
	}

	i = 0;
	for (vector<botonImagen>::iterator it = pictogramasActivos.begin(); it != pictogramasActivos.end(); it++){
		if ((*it).seHizoClic()){
			if (pictogramasActuales.size() < 5){
				vector<string> pic = getPictograma(i);
				ofImage img;
				img.loadImage(pic[1]);
				img.resize(130, 130);
				pictogramasActuales.push_back(make_pair(pic[0], img));
			}
		}
		i++;
	}


	return r;
}


espacioBase* espacioPictograma::update(float x, float y, bool clic)
{
	
	bool btnSalirRes = btnSalir->update(x, y, clic);
	bool btnAtrasRes = btnAtras->update(x, y, clic);
	bool btnAdelanteRes = btnAdelante->update(x, y, clic);
	bool btnHablarRes = btnHablar->update(x, y, clic);
	bool btnBorrarRes = btnBorrar->update(x, y, clic);
	bool btnBorrarTodoRes = btnBorrarTodo->update(x, y, clic);

	
	for (vector<botonImagen>::iterator it = btnCategorias.begin(); it != btnCategorias.end(); it++){
		(*it).update(x, y, clic);
	}

	for (vector<botonImagen>::iterator it = pictogramasActivos.begin(); it != pictogramasActivos.end(); it++){
		(*it).update(x, y, clic);
	}

	return update(btnSalirRes, btnAtrasRes, btnAdelanteRes,	btnHablarRes, btnBorrarRes, btnBorrarTodoRes);
}

espacioBase* espacioPictograma::update(float x, float y)
{

	bool btnSalirRes = btnSalir->update(x, y);
	bool btnAtrasRes = btnAtras->update(x, y);
	bool btnAdelanteRes = btnAdelante->update(x, y);
	bool btnHablarRes = btnHablar->update(x, y);
	bool btnBorrarRes = btnBorrar->update(x, y);
	bool btnBorrarTodoRes = btnBorrarTodo->update(x, y);


	for (vector<botonImagen>::iterator it = btnCategorias.begin(); it != btnCategorias.end(); it++){
		(*it).update(x, y);
	}

	for (vector<botonImagen>::iterator it = pictogramasActivos.begin(); it != pictogramasActivos.end(); it++){
		(*it).update(x, y);
	}

	return update(btnSalirRes, btnAtrasRes, btnAdelanteRes, btnHablarRes, btnBorrarRes, btnBorrarTodoRes);
}

void espacioPictograma::draw()
{
	if (btnAtrasVisible)
		btnAtras->draw();

	if (btnAdelanteVisible)
		btnAdelante->draw();

	btnHablar->draw();
	btnBorrar->draw();
	btnBorrarTodo->draw();
	btnSalir->draw();

	for (vector<botonImagen>::iterator it = btnCategorias.begin(); it != btnCategorias.end(); it++)
		(*it).draw();

	for (vector<botonImagen>::iterator it = pictogramasActivos.begin(); it != pictogramasActivos.end(); it++)
		(*it).draw();

	ofSetColor(150, 150, 150);
	ofRect(310, 20, 770, 150);


	ofSetColor(0, 255, 0);
	ofRect(1020, 30, 50, 50);
	ofSetColor(255, 0, 0);
	ofRect(1020, 90, 50, 50);

	ofSetColor(255, 255, 255);

	int offX = 320;
	int margen = 10;
	int i = 0;
	for (vector<pair<string, ofImage>>::iterator it = pictogramasActuales.begin(); it != pictogramasActuales.end(); it++){
		ofImage img = (*it).second;
		int x = offX + (i * 140);
		img.draw(x, 30);
		i++;
	}
}

void espacioPictograma::cargarPictogramas(){

	vector<string> p0 = getPictograma(0), p1 = getPictograma(1), p2 = getPictograma(2), p3 = getPictograma(3);
	pictogramasActivos.clear();
	pictogramasActivos.push_back(botonImagen(p0[1], 0.8f, p0[0], 16, ofColor(0, 0, 0), offsetX, offsetY, tam, tam));
	pictogramasActivos.push_back(botonImagen(p1[1], 0.8f, p1[0], 16, ofColor(0, 0, 0), offsetX + tam + margen, offsetY, tam, tam));
	pictogramasActivos.push_back(botonImagen(p2[1], 0.8f, p2[0], 16, ofColor(0, 0, 0), offsetX, offsetY + tam + margen, tam, tam));
	pictogramasActivos.push_back(botonImagen(p3[1], 0.8f, p3[0], 16, ofColor(0, 0, 0), offsetX + tam + margen, offsetY + tam + margen, tam, tam));

}

vector<string> espacioPictograma::getPictograma(int n){
	vector<vector<string>> picto = strPictogramas.at(categoriaActual);
	vector<string> p = picto.at(indice + n);
	return p;
}

int espacioPictograma::getTamPictograma(){
	vector<vector<string>> picto = strPictogramas.at(categoriaActual);
	return picto.size();
}

void espacioPictograma::comandoHablar(string s){

	string cmd = "-v es-la \""+ s +"\"";
	ShellExecute(NULL, "open", "C:\\Program Files (x86)\\eSpeak\\command_line\\espeak.exe", cmd.c_str(), NULL, SW_HIDE);

}

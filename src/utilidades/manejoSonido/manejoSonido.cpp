#include "manejoSonido.h"

bool manejoSonido::cargar(string s, bool stream = false){
	sp.loadSound(s);
	return sp.isLoaded();
}

void manejoSonido::reproducir(){
	sp.play();
}
#pragma once
#include <string>
#include "ofSoundPlayer.h"

using std::string;

/// Utilidad para manejar el texto a voz (en trabajo)
class manejoSonido{

public:

	manejoSonido();

	bool cargar(string, bool);
	void reproducir();

private:

	ofSoundPlayer sp;
};
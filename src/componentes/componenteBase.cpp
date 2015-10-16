#include "componenteBase.h"
#include <stdio.h>
using namespace std;

componenteBase::componenteBase(int _x, int _y, int _w, int _h)
{
	leQuedaTiempo = true;
	hayClic = false;
	mouseDentro = false;
	tiempo = 0;
	tiempoMax = 750;

	x = _x;
	y = _y;

	width = _w;
	height = _h;

	player.setMultiPlay(true);
	player.setLoop(false);
	player.loadSound("click.mp3");
}

void componenteBase::setPos(int _x, int _y)
{
	x = _x;
	y = _y;
}

void componenteBase::setTam(int _w, int _h)
{
	width = _w;
	height = _h;
}

bool componenteBase::update(float xLea, float yLea, bool clic)
{
	hayClic = false;

	if (clic && mouseEnCuadro(xLea, yLea)){
		hayClic = true;
	}
	return hayClic;
}

bool componenteBase::update(float xIn, float yIn)
{
	hayClic = false;

	if (mouseEnCuadro(xIn, yIn))
	{
		if (!mouseDentro)
		{
			mouseDentro = true;
			tiempo = getMillisec();
		}
		else
		{
			if (leQuedaTiempo)
			{
				long long int t = getMillisec();
				if (t - tiempo >= tiempoMax)
				{
					hayClic = true;
					leQuedaTiempo = false;
					player.play();
				}
			}
		}
	}
	else
	{
		mouseDentro = false;
		if (!leQuedaTiempo)
		{
			leQuedaTiempo = true;
		}
	}

	return hayClic;
}

bool componenteBase::mouseEnCuadro(float xM, float yM)
{
	return (xM >= x && yM >= y && xM <= x + width && yM <= y + height);
}

long long int componenteBase::getMillisec()
{
	auto tp = chrono::system_clock::now();
	auto duration = tp.time_since_epoch();
	long long int millis = chrono::duration_cast<chrono::milliseconds>(duration).count();
	return millis;
}

bool componenteBase::seHizoClic()
{
	return hayClic;
}

bool componenteBase::hayMouseEncima()
{
	return mouseDentro;
}
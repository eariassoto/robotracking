#include "componenteBase.h"
#include <stdio.h>
using namespace std;

componenteBase::componenteBase(int _x, int _y, int _w, int _h)
{
	leQuedaTiempo = true;

	mouseDentro = false;
	tiempo = 0;
	tiempoMax = 750;

	x = _x;
	y = _y;

	width = _w;
	height = _h;
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

bool componenteBase::update(float xIn, float yIn, float xLea, float yLea, bool clic)
{

	bool cambio = false;

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
					cambio = true;
					leQuedaTiempo = false;
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

	if (clic && mouseEnCuadro(xLea, yLea)){
		cambio = true;
	}
	return cambio;
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

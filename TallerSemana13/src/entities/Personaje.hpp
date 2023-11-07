#pragma once
#include <ctime>
#include "../utils/Dimension.hpp"

using namespace System::Drawing;
using namespace std;

#define RANDOM(a, b) a + rand()% (b - a + 1)

enum ColorPersonaje {
	AZUL,
	ROJO,
	MORADO,
	MARRON,
	PLOMO,
	ROSA
};

class Personaje abstract {
protected:
	Dimension dimension;
	int velocidadX, velocidadY;
	ColorPersonaje colorPersonaje;
public:
	Personaje(Dimension dimension, ColorPersonaje colorPersonaje): dimension(dimension) {
		velocidadX = velocidadY = 0;
	}
	ColorPersonaje getColorPersonaje() {
		return colorPersonaje;
	}
	Rectangle getArea() {
		return Rectangle(
			dimension.getX(),
			dimension.getY(),
			dimension.getAncho(),
			dimension.getAlto());
	}
	Rectangle getAreaSiguienteMov() {
		return Rectangle(
			dimension.getX() + velocidadX,
			dimension.getY() + velocidadY,
			dimension.getAncho(),
			dimension.getAlto());
	}
	void animar(Graphics^ g, Bitmap^ img) {
		mover(g);
		dibujar(g, img);
	}
	virtual void mover(Graphics^ g) abstract;
	virtual void dibujar(Graphics^ g, Bitmap^ img) abstract;
	bool existeColisionCon(Rectangle otroPersonaje) {
		return getArea().IntersectsWith(otroPersonaje);
	}
};
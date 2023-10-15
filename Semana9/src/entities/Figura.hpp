#pragma once
#include <iostream>
#include <ctime>
#include "../utils/DimensionFigura.hpp"

using namespace System::Drawing;

#define RANDOM(a,b) a + rand()% (b - a + 1)


class Figura abstract {
protected:
	DimensionFigura dimensionFigura;
	int velocidadX, velocidadY;
public: 
	Figura(DimensionFigura dimensionFigura): dimensionFigura(dimensionFigura) {
		velocidadX = velocidadY = 0;
	}
	virtual void mover(Graphics^ g) abstract;
	virtual void dibujar(Graphics^ g) abstract;
	void animar(Graphics^ g) {
		mover(g);
		dibujar(g);
	}
	Rectangle area() {
		return Rectangle(
			dimensionFigura.getX(),
			dimensionFigura.getY(),
			dimensionFigura.getAncho(),
			dimensionFigura.getAlto()
		);
	}
	bool hayColision(Rectangle obj) {
		return area().IntersectsWith(obj);
	}
	void setVelocidadX(int velocidadX) {
		this->velocidadX = velocidadX;
	}
	void setVelocidadY(int velocidadY) {
		this->velocidadY = velocidadY;
	}
};
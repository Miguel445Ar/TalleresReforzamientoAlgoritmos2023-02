#pragma once
#include <iostream>
#include "../utils/DimensionFigura.hpp"

using namespace System::Drawing;

class Figura abstract {
protected:
	DimensionFigura dimensionFigura;
	int velocidadEjeX, velocidadEjeY;
public:
	Figura(DimensionFigura dimensionFigura): dimensionFigura(dimensionFigura) {
		velocidadEjeX = velocidadEjeY = 0;
	}
	Rectangle area() {
		return Rectangle(
			dimensionFigura.getX(),
			dimensionFigura.getY(),
			dimensionFigura.getAncho(),
			dimensionFigura.getAlto()
		);
	}
	Rectangle nextArea() {
		return Rectangle(
			dimensionFigura.getX() + velocidadEjeX,
			dimensionFigura.getY() + velocidadEjeY,
			dimensionFigura.getAncho(),
			dimensionFigura.getAlto()
		);
	}
	bool existeColision(Rectangle obj) {
		return area().IntersectsWith(obj);
	}
	virtual void animar(Graphics^ graficador) {
		mover();
		dibujar(graficador);
	}
	virtual void mover() abstract {}
	virtual void dibujar(Graphics^ graficador) abstract {}
};
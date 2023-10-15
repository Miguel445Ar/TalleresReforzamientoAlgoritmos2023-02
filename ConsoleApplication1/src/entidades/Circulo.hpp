#pragma once

#include "Figura.hpp"
#include "../utils/DimensionFigura.hpp"

class Circulo : public Figura {
public:
	Circulo(int x, int y, int ancho = 50, int alto = 50)
		: Figura(DimensionFigura(x,y,ancho,alto)) {}
	void mover() override {
		dimensionFigura.setX(dimensionFigura.getX() + velocidadEjeX);
		dimensionFigura.setY(dimensionFigura.getY() + velocidadEjeY);
	}
	void dibujar(Graphics^ graficador) override {
		int x = dimensionFigura.getX();
		int y = dimensionFigura.getY();

		graficador->DrawEllipse(Pens::Green, this->area());
	}
};
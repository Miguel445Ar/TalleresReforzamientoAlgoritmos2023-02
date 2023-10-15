#pragma once
#include "Figura.hpp"

class Circulo: public Figura {
public:
	Circulo(Graphics^ g, int ancho = 50, int alto = 50)
		: Figura(DimensionFigura(ancho,alto)){
		dimensionFigura.setX(0);
		dimensionFigura.setY(RANDOM(alto, (int)g->VisibleClipBounds.Height - alto));
		velocidadX = 5;
	}
	void mover(Graphics^ g) override {
		int maxAncho = (int)g->VisibleClipBounds.Width - dimensionFigura.getAncho();
		if (dimensionFigura.getX() + velocidadX >= maxAncho
			|| dimensionFigura.getX() + velocidadX <= 0) {
			velocidadX *= -1;
		}
		dimensionFigura.setX(dimensionFigura.getX() + velocidadX);
	}
	void dibujar(Graphics^ g) override {
		g->DrawEllipse(Pens::Green, area());
	}
};
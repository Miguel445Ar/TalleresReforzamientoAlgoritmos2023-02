#pragma once
#include "Figura.hpp"

class Triangulo : public Figura {
public:
	Triangulo(Graphics^ g, int ancho = 50, int alto = 50)
		: Figura(DimensionFigura(ancho, alto)) {
		dimensionFigura.setX(RANDOM(0, (int)g->VisibleClipBounds.Width - ancho));
		dimensionFigura.setY(0);
		velocidadY = 5;
	}
	void mover(Graphics^ g) override {
		int maxAlto = (int)g->VisibleClipBounds.Height - dimensionFigura.getAlto();
		if (dimensionFigura.getY() + velocidadY >= maxAlto
			|| dimensionFigura.getY() + velocidadY <= 0) {
			velocidadY *= -1;
		}
		dimensionFigura.setY(dimensionFigura.getY() + velocidadY);
	}
	void dibujar(Graphics^ g) override {
		g->DrawEllipse(Pens::Green, area());
	}
};
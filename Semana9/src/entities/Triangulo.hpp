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
		/*g->DrawEllipse(Pens::Green, area());*/
		int x = dimensionFigura.getX();
		int y = dimensionFigura.getY();
		int ancho = dimensionFigura.getAncho();
		int alto = dimensionFigura.getAlto();
		Point p1(x, y);
		Point p2(x, y + alto);
		Point p3(x + ancho, y + alto);
		array<Point>^ puntos = { p1, p2, p3 };
		g->DrawPolygon(Pens::Green, puntos);
	}
};
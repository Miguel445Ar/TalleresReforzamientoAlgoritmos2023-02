#pragma once

class DimensionFigura {
	int x, y, ancho, alto;
public:
	DimensionFigura(int ancho, int alto, int x = 0, int y = 0)
		: x(x), y(y), ancho(ancho), alto(alto) {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getAncho() {
		return ancho;
	}
	int getAlto() {
		return alto;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
};
#pragma once

class DimensionFigura {
	int x;
	int y;
	int ancho;
	int alto;
public:
	DimensionFigura(int x, int y, int ancho, int alto): x(x), y(y), ancho(ancho), alto(alto) {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getAncho() {
		return ancho;
	}
	int getAlto() {
		return alto;
	}
};
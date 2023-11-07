#pragma once
#include <iostream>

class Dimension {
	int x, y, ancho, alto;
public:
	Dimension(int x, int y, int ancho, int alto)
		:x(x), y(y), ancho(ancho), alto(alto) {}
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
	void setX(int velocidadX) {
		x += velocidadX;
	}
	void setY(int velocidadY) {
		y += velocidadY;
	}
	void setAncho(int ancho) {
		this->ancho = ancho;
	}
	void setAlto(int alto) {
		this->alto = alto;
	}
};
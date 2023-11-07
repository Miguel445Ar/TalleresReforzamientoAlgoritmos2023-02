#pragma once
#include "Personaje.hpp"

class PersonajeRojo : public Personaje {
	int cantidadFilasImagen;
	int cantidadColumnasImagen;
	int yImagen;
	int xImagen;
public:
	PersonajeRojo(Graphics^ g, int ancho = 50, int alto = 50) : Personaje(Dimension(0, 0, ancho, alto), ColorPersonaje::ROJO) {
		int maxX = g->VisibleClipBounds.Width - ancho;
		int maxY = g->VisibleClipBounds.Height - alto;
		this->dimension.setX(RANDOM(10, maxX));
		this->dimension.setY(RANDOM(10, maxY));
		velocidadX = RANDOM(0, 10) - 5;// Numero aleatorio entre -5 y 5 
		velocidadY = RANDOM(0, 10) - 5;// Numero aleatorio entre -5 y 5
		cantidadColumnasImagen = 6;
		cantidadFilasImagen = 5;
		yImagen = 0;
		xImagen = 1;
	}
	Rectangle setAreaDeRecorteImagen(Bitmap^ img) {
		int anchoImagenCompleta = img->Width;
		int altoImagenCompleta = img->Height;
		int anchoImagenRecortada = anchoImagenCompleta / cantidadColumnasImagen;
		int altoImagenRecortada = altoImagenCompleta / cantidadFilasImagen;
		int y = yImagen * altoImagenRecortada;
		int x = xImagen * anchoImagenRecortada;
		return Rectangle(x, y, anchoImagenRecortada, altoImagenRecortada);
	}
	void dibujar(Graphics^ g, Bitmap^ img) override {
		Rectangle areaRecorteImagen = setAreaDeRecorteImagen(img);
		g->DrawImage(img, areaRecorteImagen);
		/*if (yImagen == 5) yImagen = 0;
		else ++yImagen;*/
		yImagen = ++yImagen % 5;
	}
	void mover(Graphics^ g) override {
		int x = this->dimension.getX();
		int y = this->dimension.getY();
		int ancho = this->dimension.getAncho();
		int alto = this->dimension.getAlto();
		if (x + ancho + velocidadX >= g->VisibleClipBounds.Width || x + velocidadX <= 0)
			velocidadX *= -1;
		if (y + alto + velocidadY >= g->VisibleClipBounds.Height || y + velocidadY <= 0)
			velocidadY *= -1;
		this->dimension.setX(velocidadX);
		this->dimension.setY(velocidadY);
	}
};
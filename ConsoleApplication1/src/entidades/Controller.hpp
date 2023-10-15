#pragma once
#include "GestorDeFiguras.hpp"
#include "Circulo.hpp"
#include <vector>
#include <ctime>

using namespace std;
using namespace System::Windows::Forms;

#define RANDOM(a,b) a + rand()% (b - a + 1)

ref class Controller {
	GestorDeFiguras* gestorDeFiguras;
public:
	Controller() {
		srand(time(0));
		gestorDeFiguras = new GestorDeFiguras();
	}
	~Controller() {
		delete gestorDeFiguras;
	}
	void detectarTeclas(Keys key, Graphics^ graficador) {
		if (key == Keys::C) {
			addCirculo(graficador);
			return;
		}
	}
	void animar(Graphics^ graficador) {
		int x = 6;
		gestorDeFiguras->animarFiguras(graficador);
	}
	void addCirculo(Graphics^ graficador) {
		int x = RANDOM(0, static_cast<int>(graficador->VisibleClipBounds.Width));
		int y = RANDOM(0, static_cast<int>(graficador->VisibleClipBounds.Height));
		Circulo* circulo = new Circulo(x,y);
		gestorDeFiguras->addFigura(circulo);
	}
};
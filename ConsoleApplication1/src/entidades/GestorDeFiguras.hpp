#pragma once
#include "Figura.hpp"
#include <vector>
#include <iostream>

using namespace std;

class GestorDeFiguras {
	vector<Figura*> figuras;
public:
	GestorDeFiguras() {
		figuras = vector<Figura*>();
	}
	~GestorDeFiguras() {}
	void animarFiguras(Graphics^ graficador) {

		for (Figura* figura : figuras) {
			figura->animar(graficador);
		}
	}
	void addFigura(Figura* figura){
		figuras.push_back(figura);
	}
private:
	void vaciarFiguras() {
		//while (!figuras.empty()) {
		//	vector<Figura*>::iterator it = figuras.end();
		//	delete (*it);
		//	figuras.pop_back();
		//}
	}
};
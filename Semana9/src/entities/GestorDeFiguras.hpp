#pragma once
#include "Circulo.hpp"
#include "Triangulo.hpp"
#include <vector>

using std::vector;

class GestorDeFiguras {
	vector<Circulo*> circulos;
	vector<Triangulo*> triangulos;
public:
	GestorDeFiguras() {}
	~GestorDeFiguras() {
		for (int i = circulos.size() - 1; i >= 0; --i) {
			delete circulos[i];
			circulos.erase(circulos.begin() + i);
		}
		for (int i = triangulos.size() - 1; i >= 0; --i) {
			delete triangulos[i];
			triangulos.erase(triangulos.begin() + i);
		}
	}
	void addTriangulo(Graphics^ g) {
		triangulos.push_back(new Triangulo(g));
	}
	void addCirculo(Graphics^ g) {
		circulos.push_back(new Circulo(g));
	}
	void animar(Graphics^ g) {
		animarCirculos(g);
		animarTriangulos(g);
	}
	void eliminarFigurasColisionados() {
		for (int i = triangulos.size() - 1; i >= 0; --i) {
			if (!existeColisionConCirculo(triangulos[i])) continue;
			delete triangulos[i];
			triangulos.erase(triangulos.begin() + i);
		}
	}
	int getCantidadCirculos() {
		return this->circulos.size();
	}
	int getCantidadTriangulos() {
		return this->triangulos.size();
	}
private:
	void animarTriangulos(Graphics^ g) {
		for (Triangulo* triangulo : triangulos)
			triangulo->animar(g);
	}
	void animarCirculos(Graphics^ g) {
		for (Circulo* circulo : circulos)
			circulo->animar(g);
	}
	bool existeColisionConCirculo(Triangulo* triangulo) {
		bool hayColision = false;
		for (int i = circulos.size() - 1; i >= 0; --i) {
			if (!circulos[i]->hayColision(triangulo->area())) continue;
			delete circulos[i];
			circulos.erase(circulos.begin() + i);
			hayColision = true;
		}
		return hayColision;
	}
};
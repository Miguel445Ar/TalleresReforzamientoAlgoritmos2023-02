#pragma once
#include "../entities/GestorDeFiguras.hpp"

using namespace System::Windows::Forms;

ref class Controller {
	GestorDeFiguras* gestorDeFiguras;
public:
	Controller() {
		gestorDeFiguras = new GestorDeFiguras();
	}
	~Controller() {
		delete gestorDeFiguras;
	}
	void detectarTeclas(Graphics^ g, Keys tecla) {
		if (tecla == Keys::Space) {
			gestorDeFiguras->addTriangulo(g);
		}
		if (tecla == Keys::Enter) {
			gestorDeFiguras->addCirculo(g);
		}
	}
	void animar(Graphics^ g) {
		gestorDeFiguras->eliminarFigurasColisionados();
		gestorDeFiguras->animar(g);
	}

};
#pragma once
#include "../entities/GestorDeFiguras.hpp"
#include "../utils/FileHandler.hpp"
#include <ctime>

using namespace System::Windows::Forms;

ref class Controller {
	GestorDeFiguras* gestorDeFiguras;
	FileHandler* fileHandler;
	int duracion;
public:
	Controller() {
		gestorDeFiguras = new GestorDeFiguras();
		fileHandler = new FileHandler();
		duracion = fileHandler->getDuracionEnSegundos();
	}
	~Controller() {
		delete gestorDeFiguras;
		delete fileHandler;
	}
	void detectarTeclas(Graphics^ g, Keys tecla) {
		if (tecla == Keys::Space) {
			gestorDeFiguras->addTriangulo(g);
		}
		if (tecla == Keys::Enter) {
			gestorDeFiguras->addCirculo(g);
		}
	}
	bool animar(Graphics^ g) {
		imprimirTiempoRestante(g);
		gestorDeFiguras->eliminarFigurasColisionados();
		gestorDeFiguras->animar(g);
		bool seTerminoElTiempo = tiempoTerminado();
		if (seTerminoElTiempo) {
			int cantidadCirculos = gestorDeFiguras->getCantidadCirculos();
			int cantidadTriangulos = gestorDeFiguras->getCantidadTriangulos();
			fileHandler->guardarDatosDeFiguras(cantidadCirculos, cantidadTriangulos);
		}
		return seTerminoElTiempo;
	}
	int getCantidadCirculos() {
		return gestorDeFiguras->getCantidadCirculos();
	}
	int getCantidadTriangulos() {
		return gestorDeFiguras->getCantidadTriangulos();
	}
private:
	void imprimirTiempoRestante(Graphics^ g) {
		int segundosRestantes = tiempoRestanteEnTicks() / 1000;
		g->DrawString("Tiempo restante: " + segundosRestantes, gcnew Font("Arial", 10), Brushes::Red, 5, 5);
	}
	int tiempoRestanteEnTicks() {
		return (duracion * 1000) - clock();
	}
	bool tiempoTerminado() {
		return (duracion * 1000) - clock() <= 0;
	}

};
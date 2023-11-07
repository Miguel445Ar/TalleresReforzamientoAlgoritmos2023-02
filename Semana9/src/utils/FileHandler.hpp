#pragma once
#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ofstream;
using std::ifstream;

class FileHandler {
public:
	FileHandler() {
		duracionEnSegundos = 0;
		leerArchivo();
	}
	int getDuracionEnSegundos() {
		return duracionEnSegundos;
	}
	void guardarDatosDeFiguras(int cantidadCirculos, int cantidadTriangulos) {
		modificadorYCreadorDeArchivos.open("estadisticas.txt");
		modificadorYCreadorDeArchivos << "Circulos restantes: " << cantidadCirculos << "\n";
		modificadorYCreadorDeArchivos << "Triangulos restantes: " << cantidadTriangulos;
		modificadorYCreadorDeArchivos.close();
	}
private:
	void leerArchivo() {
		lectorDeArchivos.open("datos.txt");
		if (lectorDeArchivos.is_open() == false) {
			crearArchivoConValorPorDefecto();
			return;
		}
		string line;
		lectorDeArchivos >> line;
		duracionEnSegundos = std::stoi(line);
		lectorDeArchivos.close();
	}
	void crearArchivoConValorPorDefecto() {
		modificadorYCreadorDeArchivos.open("datos.txt");
		modificadorYCreadorDeArchivos << "20";
		duracionEnSegundos = 20;
		modificadorYCreadorDeArchivos.close();
	}
private:
	int duracionEnSegundos;
	std::ifstream lectorDeArchivos;
	std::ofstream modificadorYCreadorDeArchivos;
};
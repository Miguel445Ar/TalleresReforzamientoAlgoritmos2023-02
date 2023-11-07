#pragma once
#include <iostream>
#include <fstream>

using std::ifstream; // Solo para leer archivos
using std::ofstream; // Solo para escribir o crear y escribir en archivos
using std::fstream;

class ManejadorArchivos {
	ifstream lectorDeArchivos;
	ofstream escritorDeArchivos;
	int s;
	int t;
public:
	ManejadorArchivos() {
		leerArchivo();
	}
	int getSegundosAparicionPersonajes() {
		return s;
	}
	int getDuracionDelJuego() {
		return t;
	}
private:
	void leerArchivo() {
		lectorDeArchivos.open("configuracion.txt");
		if (lectorDeArchivos.is_open() == false) {
			crearArchivo();
			return;
		}
		// 2
		// 5
		int s;
		int t;
		lectorDeArchivos >> s;
		lectorDeArchivos >> t;
		lectorDeArchivos.close();
	}
	void crearArchivo() {
		s = 2;
		t = 5;
		escritorDeArchivos.open("configuracion.txt");
		escritorDeArchivos << s << "\n" << t;
		escritorDeArchivos.close();
	}
};
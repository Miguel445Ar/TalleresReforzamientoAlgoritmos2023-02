#pragma once
#include "../entities/PersonajeRojo.hpp"

using namespace System::Drawing;

ref class Controlador {
	Bitmap^ imgPersonaje;
public:
	Controlador() {
		imgPersonaje = gcnew Bitmap("sprites.png");
		// imgPersonaje = Bitmap::FromFile("");
	}
	~Controlador() {
		delete imgPersonaje;
	}
	bool animar() {
		return true;
	}
};
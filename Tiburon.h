#pragma once
#include "Base.h"
class Tiburon : public Base
{
private:
	int vidas;
public:
	Tiburon();
	Tiburon(int px, int py, int pw, int ph);
	~Tiburon();
	void cambiar_vidas(int nuevo);
	int retornar_vidas();
	void Desplazamiento_NPC();
	void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
};


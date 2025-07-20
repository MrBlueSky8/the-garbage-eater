#pragma once
#include "Base.h"
#include "iostream"
class Basura : public Base
{
public:
	Basura();
	Basura(int px, int py, int pw, int ph);
	~Basura();
	void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
};
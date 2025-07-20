#include "Piraña.h"
Piraña::Piraña() {}
Piraña::Piraña(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 2, 6, 0, 0)
{
	System::Random^ r = gcnew System::Random();

	dx = -(gcnew System::Random())->Next(6, 9);
	dy = (gcnew System::Random())->Next(5, 11);

	vidas = (gcnew System::Random())->Next(1, 4);
	//vidas = r->Next(1, 4);

	delete r;
}
Piraña::~Piraña() {}
void Piraña::cambiar_vidas(int nuevo) { vidas = nuevo; }
int Piraña::retornar_vidas() { return vidas; }
void Piraña::Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp)
{
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	col++;
	if (col == max_col)
	{
		col = 0;
	}
}
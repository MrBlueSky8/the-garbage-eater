#include "Pajaro.h"
Pajaro::Pajaro() {}
Pajaro::Pajaro(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 1, 4, 0, 0)
{
	System::Random^ r = gcnew System::Random();

	dx = (gcnew System::Random())->Next(26, 35);

	delete r;
}
Pajaro::~Pajaro() {}
void Pajaro::Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp)
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
void Pajaro::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w > g->VisibleClipBounds.Width)
	{
		dx = 0;
	}

	x = x + dx;
	
}

#include "Basura.h"
Basura::Basura() {}
Basura::Basura(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 4, 4, 0 + rand() % 4, 0 + rand() % 4)
{

}
Basura::~Basura() {}
void Basura::Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp)
{
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
}
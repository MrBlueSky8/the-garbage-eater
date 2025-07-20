#include "Tiburon.h"
Tiburon::Tiburon() {}
Tiburon::Tiburon(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 4, 3, 2, 0)
{
	System::Random^ r = gcnew System::Random();

	dy = r->Next(6, 16);
	dx = -(r->Next(7, 16));

	vidas= r->Next(2, 5);

	delete r;
}
Tiburon::~Tiburon() {}
void Tiburon::cambiar_vidas(int nuevo) { vidas = nuevo; }
int Tiburon::retornar_vidas() { return vidas; }
void Tiburon::Desplazamiento_NPC()
{
	if (dx >= 1) { fil = 2; orientacion_npc = direccion::derecha; }
	if (dx <= -1) { fil = 1; orientacion_npc = direccion::izquierda; }

	if (dy >= 1 && dx == 0) { fil = 0; orientacion_npc = direccion::abajo; }
	if (dy <= -1 && dx == 0) { fil = 3; orientacion_npc = direccion::arriba; }
}
void Tiburon::Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp)
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
#include "Flecha.h"
Flecha::Flecha()
{

}
Flecha::Flecha(int px, int py, int pw, int ph) : Base(px, py, pw, ph, 1, 4, 0, 0)
{
	System::Random^ r = gcnew System::Random();
}
Flecha::~Flecha()
{

}
void Flecha::Mover(Graphics^ g)
{
	if (y + dy < 1)
	{
		dy = 0;
		eliminar = true;
	}
	if (y + dy + h > g->VisibleClipBounds.Height)
	{
		dy = 0;
		eliminar = true;
	}
	if (x + dx < 1)
	{
		dx = 0;
		eliminar = true;
	}
	if (x + dx + w > g->VisibleClipBounds.Width)
	{
		dx = 0;
		eliminar = true;
	}

	y += dy;
	x += dx;
}
void Flecha::Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp)
{
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	/*col++;
	if (col == max_col)
	{
		
	}
	*/
}
void Flecha::Desplazamiento_NPC()
{
	if (dx >= 1) { col = 3; orientacion_npc = direccion::derecha; }
	if (dx <= -1) { col = 1; orientacion_npc = direccion::izquierda; }

	if (dy >= 1 && dx == 0) { col = 2; orientacion_npc = direccion::abajo; }
	if (dy <= -1 && dx == 0) { col = 0; orientacion_npc = direccion::arriba; }
}
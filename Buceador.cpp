#include "Buceador.h"
Buceador::Buceador() {}
Buceador::Buceador(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 4, 4, 2, 0)
{
	fraccion_movimientoX = 4;
	fraccion_movimientoY = 4;
	Desplazamiento(direccion::arriba);
	velocidadx2 = false;
}
Buceador::~Buceador() {}
void Buceador::Mover(Graphics^ g)
{
	
	if (velocidadx2 == true && fraccion_movimientoX == 4)
	{
		inicio = clock();
		fraccion_movimientoX = 2;
		fraccion_movimientoY = 2;
	}
	if ((velocidadx2 == true) && ((clock() - inicio) / CLOCKS_PER_SEC > 4))
	{
		fraccion_movimientoX = 4;
		fraccion_movimientoY = 4;

		velocidadx2 = false;
	}
	if (velocidadx2 == false)
	{
		fraccion_movimientoX = 4;
		fraccion_movimientoY = 4;
	}

	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx = 0;
	if (y + dy<145 || y + dy + h>g->VisibleClipBounds.Height) dy = 0;

	x += dx;
	y += dy;
}
void Buceador::Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp)
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
void Buceador::Disparar()
{
	System::Random^ r = gcnew System::Random();

	if (dx != 0 || dy != 0)
	{
		flechas.push_back(new Flecha(x + w / 2, y, 1, 1));
	}
	else if (orientacion == direccion::arriba)
	{
		flechas.push_back(new Flecha(x + w / 2, y, 1, 1));
		flechas.at(flechas.size() - 1)->cambiar_dy(-(r->Next(17, 27)));
	}
	if (dx > 1)
		flechas.at(flechas.size() - 1)->cambiar_dx(r->Next(17, 27));
	if (dx < -1)
		flechas.at(flechas.size() - 1)->cambiar_dx(-(r->Next(17, 27)));
	if (dy > 1)
		flechas.at(flechas.size() - 1)->cambiar_dy(r->Next(17, 27));
	if (dy < -1)
		flechas.at(flechas.size() - 1)->cambiar_dy(-(r->Next(17, 27)));
}
void Buceador::Mover_Flechas(Graphics^ g, Bitmap^ bmpflechas)
{
	System::Random^ r = gcnew System::Random();
	//dy = -(r->Next(4, 11));
	for (int i = 0; i < flechas.size(); i++)
	{
		flechas.at(i)->Desplazamiento_NPC();
		flechas.at(i)->Dibujar_desdeImagen(g, bmpflechas);
		flechas.at(i)->Mover(g);
	}

	for (int i = 0; i < flechas.size(); i++)
	{
		if (flechas.at(i)->retornar_eliminar() == true)
			flechas.erase(flechas.begin() + i);
	}
}
vector<Flecha*> Buceador::retornar_flechas() { return flechas; }
int Buceador::retornar_cant_flechas() { return flechas.size(); }
Flecha* Buceador::retornar_flecha_enindice(int indice) { return flechas.at(indice); }
void Buceador::borrar_flechas()
{
	for (int i = 0; i < flechas.size(); i++)
	{
		if (flechas.at(i)->retornar_eliminar() == true)
			flechas.erase(flechas.begin() + i);
	}
}
void Buceador::cambiar_velocidad(bool nuevo) { velocidadx2 = nuevo; }
bool Buceador::retornar_velocidadx2() { return velocidadx2; }
void Buceador::cambiar_inicio() { inicio = clock(); }
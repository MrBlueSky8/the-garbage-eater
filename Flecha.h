#pragma once
#include "Base.h"
class Flecha :
    public Base
{
public:
    Flecha();
    Flecha(int px, int py, int pw, int ph);
    ~Flecha();
    void Mover(Graphics^ g);
    void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
    void Desplazamiento_NPC();
};
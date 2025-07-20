#pragma once
#include "Base.h"
class Pajaro :    public Base
{
public:
    Pajaro();
    Pajaro(int px, int py, int pw, int ph);
    ~Pajaro();
    void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
    void Mover(Graphics^ g);
};


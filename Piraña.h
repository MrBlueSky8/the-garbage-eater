#pragma once
#include "Base.h"
#include "iostream"
using namespace std;
class Piraña : public Base
{
private:
    int vidas;
public:
    Piraña();
    Piraña(int px, int py, int pw, int ph);
    ~Piraña();
    void cambiar_vidas(int nuevo);
    int retornar_vidas();
    void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
    //void Desplazamiento_NPC();
};
#pragma once
#include "Base.h"
#include "iostream"
using namespace std;
class Pira�a : public Base
{
private:
    int vidas;
public:
    Pira�a();
    Pira�a(int px, int py, int pw, int ph);
    ~Pira�a();
    void cambiar_vidas(int nuevo);
    int retornar_vidas();
    void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
    //void Desplazamiento_NPC();
};
#pragma once
#include "time.h"
#include "vector"
#include "Base.h"
#include "Flecha.h"
using namespace std;
class Buceador : public Base
{
private:
    vector<Flecha*> flechas;
    bool velocidadx2;
    time_t inicio;
public:
    Buceador();
    Buceador(int px, int py, int pw, int ph);
    ~Buceador();
    void Mover(Graphics^ g);
    void Dibujar_desdeImagen(Graphics^ g, Bitmap^ bmp);
    void Disparar();
    void Mover_Flechas(Graphics^ g, Bitmap^ bmpflechas);
    vector<Flecha*> retornar_flechas();
    int retornar_cant_flechas();
    Flecha* retornar_flecha_enindice(int indice);
    void borrar_flechas();
    void cambiar_velocidad(bool nuevo);
    bool retornar_velocidadx2();
    void cambiar_inicio();
};

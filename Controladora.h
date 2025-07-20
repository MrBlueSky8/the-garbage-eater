#pragma once
#include "vector"
#include "Basura.h"
#include "Bonus.h"
#include "Buceador.h"
#include "Piraña.h"
#include "Tiburon.h"
#include "Arpon.h"
#include "Loading.h"
#include "Pajaro.h"
using namespace std;
class Controladora
{
private:
    vector<Piraña*> pirañas;
    vector<Bonus*> bonuses;
    vector<Basura*> basuras;
    vector<Tiburon*> tiburones;
    vector<Arpon*> arpones;
    vector<Pajaro*> pajaros;
    Buceador* objbuceador;
    Loading* objloading;

    time_t inicio;
    time_t intervalo_pajaros;
    int nivel;
    int vidas;
    bool cerrar;
    bool pasar_nivel;
    int contador_basuras;
    int cantidad_de_arpones;
    int cantidad_de_basuras;
    int municion;
    int puntaje_total;

    bool parametro_establecido;
    bool bird_bonus;
public:
    Controladora();
    void Generar_Pajaros();
    void Parametros_nivel();
    void Dibujar_Pajaros(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Loading(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Buceador(Graphics^ g, Bitmap^ bmp);
    void Desplazar_Buceador(direccion movimiento);
    void Dibujar_Bonus(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Pirañas(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Tiburones(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Basuras(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Arpones(Graphics^ g, Bitmap^ bmp);
    void Disparar();
    void Dibujar_Balas(Graphics^ g, Bitmap^ bmp);
    bool Colision_con_bonus();
    bool Colision_con_tiburones();
    bool Colision_con_pirañas();
    bool Colision_con_basuras();
    bool Colision_buceador_arpon();
    bool Colision_flechas_pirañas();
    bool Colision_flechas_tiburones();
    bool Colision_flechas_pajaros();
    ~Controladora();
    void cambiar_nivel(int nuevo);
    int retornar_nivel();
    bool retornar_cerrar();
    bool retornar_pasar_nivel();
    int retornar_vidas();
    int retornar_municion();
    int retornar_contador_de_basura();
    time_t Retornar_inicio();
    void Restart_inicio();
    void GrabarenArchivo(vector<string> datos);
    int retornar_puntaje();
};


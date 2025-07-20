#include "Controladora.h"
Controladora::Controladora()
{
	System::Random^ r = gcnew System::Random();
	

	for (int i = 0; i <= 10; i++)
		bonuses.push_back(new Bonus(r->Next(100, 1300), r->Next(145, 750), 10, 10));


	cantidad_de_arpones = 5;
	for (int i = 0; i <= cantidad_de_arpones; i++)
		arpones.push_back(new Arpon(r->Next(100, 1300), r->Next(145, 700), 10, 10));

	objbuceador = new Buceador(10, 145, 1, 1);
	objloading = new Loading(10, 100, 1, 1);
	nivel = 1;
	vidas = 3;
	cerrar = false;
	pasar_nivel = false;
	contador_basuras = 0;
	municion = 5;
	puntaje_total = 0;

	parametro_establecido = false;
	bird_bonus = false;
	inicio = clock();
	intervalo_pajaros = clock();
}
void Controladora::Generar_Pajaros()
{
	System::Random^ r = gcnew System::Random();

	if (((clock() - intervalo_pajaros) / CLOCKS_PER_SEC > 5) && bird_bonus == false && municion == 1)
	{
		System::Random^ r = gcnew System::Random();

		
		pajaros.push_back(new Pajaro(1, 1, 1, 1));
		//pajaros.at(pajaros.size() - 1)->cambiar_x(1);

		intervalo_pajaros = clock();
		delete r;
	}

}
void Controladora::Dibujar_Pajaros(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < pajaros.size(); i++)
	{
		pajaros.at(i)->Dibujar_desdeImagen(g, bmp);
		pajaros.at(i)->Mover(g);
		
		if (pajaros.at(i)->retornar_dx() == 0)
		{
			pajaros.at(i)->cambiar_eliminar(true);

			for (int j = 0; j < pajaros.size(); j++)
			{
				if (pajaros.at(j)->retornar_eliminar() == true)
					pajaros.erase(pajaros.begin() + j);
			}
		}
		
	}
}
void Controladora::Parametros_nivel()
{
	System::Random^ r = gcnew System::Random();

	if (nivel == 1 && parametro_establecido == false)
	{
		cantidad_de_basuras = 100;
		for (int i = 0; i < cantidad_de_basuras; i++)
			basuras.push_back(new Basura(r->Next(100, 1350), r->Next(145, 700), 10, 10));

		for (int i = 0; i < 6; i++)
			pirañas.push_back(new Piraña(r->Next(100, 1000), r->Next(150, 750), 10, 10));

		parametro_establecido = true;
	}
	if (nivel == 2 && parametro_establecido==false)
	{
		cantidad_de_basuras = 150;
		for (int i = 0; i < cantidad_de_basuras; i++)
			basuras.push_back(new Basura(r->Next(100, 1350), r->Next(145, 700), 10, 10));


		for (int i = 0; i < 8; i++)
			tiburones.push_back(new Tiburon(r->Next(100, 1000), r->Next(150, 750), 15, 15));

		parametro_establecido = true;
	}
}
void Controladora::Dibujar_Loading(Graphics^ g, Bitmap^ bmp)
{
	objloading->Dibujar_desdeImagen(g, bmp);
}
void Controladora::Dibujar_Buceador(Graphics^ g, Bitmap^ bmp)
{
	objbuceador->Dibujar_desdeImagen(g, bmp);
	objbuceador->Mover(g);
	Colision_con_basuras();
	Colision_con_bonus();
	Colision_buceador_arpon();
	Colision_flechas_pajaros();
	if (nivel == 1)
	{
		Colision_con_pirañas();
		Colision_flechas_pirañas();
	}
	else
	{
		Colision_con_tiburones();
		Colision_flechas_tiburones();
	}
	if (((clock() - inicio) / CLOCKS_PER_SEC > 120 && nivel == 2))
	{
		puntaje_total = (contador_basuras * vidas * 1000) / ((clock() - inicio) / CLOCKS_PER_SEC);
		cerrar = true;
	}
	if ((clock() - inicio) / CLOCKS_PER_SEC > 180)
	{
		puntaje_total = (contador_basuras * vidas * 1000) / ((clock() - inicio) / CLOCKS_PER_SEC);
		cerrar = true;
	}
}
void Controladora::Desplazar_Buceador(direccion movimiento)
{
	objbuceador->Desplazamiento(movimiento);
}
void Controladora::Dibujar_Bonus(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < bonuses.size(); i++)
	{
		bonuses.at(i)->Dibujar_desdeImagen(g, bmp);
	}
}
void Controladora::Dibujar_Pirañas(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < pirañas.size(); i++)
	{
		pirañas.at(i)->Desplazamiento_NPC();
		pirañas.at(i)->Dibujar_desdeImagen(g, bmp);
		pirañas.at(i)->Mover(g);
	}
}
void Controladora::Dibujar_Tiburones(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < tiburones.size(); i++)
	{
		tiburones.at(i)->Desplazamiento_NPC();
		tiburones.at(i)->Dibujar_desdeImagen(g, bmp);
		tiburones.at(i)->Mover(g);
	}
}
void Controladora::Dibujar_Basuras(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < basuras.size(); i++)
	{
		basuras.at(i)->Dibujar_desdeImagen(g, bmp);
	}
}
void Controladora::Dibujar_Arpones(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < arpones.size(); i++)
	{
		arpones.at(i)->Dibujar_desdeImagen(g, bmp);
	}
}
void Controladora::Disparar()
{
	if (municion > 0)
	{
		objbuceador->Disparar();
		municion--;
	}
}
void Controladora::Dibujar_Balas(Graphics^ g, Bitmap^ bmp)
{

	objbuceador->Mover_Flechas(g, bmp);
}
bool Controladora::Colision_con_bonus()
{
	bool resultado_colision = false;
	Rectangle r1 = objbuceador->retornar_rectangle();
	for (int j = 0; !resultado_colision && j < bonuses.size(); j++)
	{
		Rectangle r2 = bonuses.at(j)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision = true;
			bonuses.at(j)->cambiar_eliminar(true);
			for (int i = 0; i < bonuses.size(); i++)
			{
				if (bonuses.at(i)->retornar_eliminar() == true)
					bonuses.erase(bonuses.begin() + i);
			}
			if (objbuceador->retornar_velocidadx2() == true)
				objbuceador->cambiar_inicio();
			objbuceador->cambiar_velocidad(true);
		}
	}
	return resultado_colision;
}
bool Controladora::Colision_con_tiburones()
{
	bool resultado_colision = false;
	Rectangle r1 = objbuceador->retornar_rectangle();
	for (int j = 0; !resultado_colision && j < tiburones.size(); j++)
	{
		Rectangle r2 = tiburones.at(j)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision = true;
			if (vidas > 0)
			{
				vidas = vidas - 1;

				objbuceador->cambiar_x(10);
				objbuceador->cambiar_x(25);
				objbuceador->cambiar_velocidad(false);
			}
			if (vidas == 0)
			{
				puntaje_total = (contador_basuras * 1000) / ((clock() - inicio) / CLOCKS_PER_SEC);
				cerrar = true;
			}
		}
	}
	return resultado_colision;
}
bool Controladora::Colision_con_pirañas()
{
	bool resultado_colision = false;
	Rectangle r1 = objbuceador->retornar_rectangle();
	for (int j = 0; !resultado_colision && j < pirañas.size(); j++)
	{
		Rectangle r2 = pirañas.at(j)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision = true;
			if (vidas > 0)
			{
				vidas = vidas - 1;

				objbuceador->cambiar_x(10);
				objbuceador->cambiar_x(25);
				objbuceador->cambiar_velocidad(false);
			}
			if (vidas == 0)
			{
				puntaje_total = (contador_basuras * 1000) / ((clock() - inicio) / CLOCKS_PER_SEC);
				cerrar = true;
			}
		}
	}
	return resultado_colision;
}
bool Controladora::Colision_con_basuras()
{
	bool resultado_colision = false;
	Rectangle r1 = objbuceador->retornar_rectangle();
	for (int j = 0; !resultado_colision && j < basuras.size(); j++)
	{
		Rectangle r2 = basuras.at(j)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision = true;
			contador_basuras++;
			if (contador_basuras == 30 || contador_basuras == 60 || contador_basuras == 90) vidas++;
			basuras.at(j)->cambiar_eliminar(true);
			for (int i = 0; i < basuras.size(); i++)
			{
				if (basuras.at(i)->retornar_eliminar() == true)
					basuras.erase(basuras.begin() + i);
			}

			if (contador_basuras == 100 && nivel == 1)
			{
				puntaje_total = (contador_basuras * vidas * 1000) / ((clock() - inicio) / CLOCKS_PER_SEC);
				nivel = 2;
				//cerrar = true;
				pasar_nivel = true;
			}
			else if (contador_basuras == 150)
			{
				puntaje_total = (contador_basuras * vidas * 1000) / ((clock() - inicio) / CLOCKS_PER_SEC);
				//cerrar = true;
				pasar_nivel = true;
			}
		}
	}
	return resultado_colision;
}
bool Controladora::Colision_buceador_arpon()
{
	bool resultado_colision = false;

	Rectangle r1 = objbuceador->retornar_rectangle();
	for (int j = 0; !resultado_colision && j < arpones.size(); j++)
	{
		Rectangle r2 = arpones.at(j)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision = true;
			municion++;
			arpones.at(j)->cambiar_eliminar(true);
			for (int i = 0; i < arpones.size(); i++)
			{
				if (arpones.at(i)->retornar_eliminar() == true)
					arpones.erase(arpones.begin() + i);
			}
		}
	}

	return resultado_colision;
}
bool Controladora::Colision_flechas_pirañas()
{
	bool resultado_colision = false;

	for (int i = 0; i < objbuceador->retornar_cant_flechas(); i++)
	{
		Rectangle r1 = objbuceador->retornar_flecha_enindice(i)->retornar_rectangle();
		for (int j = 0; !resultado_colision && j < pirañas.size(); j++)
		{
			Rectangle r2 = pirañas.at(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				resultado_colision = true;
				objbuceador->retornar_flecha_enindice(i)->cambiar_eliminar(true);

				if (pirañas.at(j)->retornar_vidas() > 0)
				{
					pirañas.at(j)->cambiar_vidas(pirañas.at(j)->retornar_vidas() - 1);
				}
				if (pirañas.at(j)->retornar_vidas() == 0)
				{
					pirañas.at(j)->cambiar_eliminar(true);
				}

				objbuceador->borrar_flechas();

				for (int i = 0; i < pirañas.size(); i++)
				{
					if (pirañas.at(i)->retornar_eliminar() == true)
						pirañas.erase(pirañas.begin() + i);
				}

			}
		}
	}

	return resultado_colision;
}
bool Controladora::Colision_flechas_tiburones()
{
	bool resultado_colision = false;

	for (int i = 0; i < objbuceador->retornar_cant_flechas(); i++)
	{
		Rectangle r1 = objbuceador->retornar_flecha_enindice(i)->retornar_rectangle();
		for (int j = 0; !resultado_colision && j < tiburones.size(); j++)
		{
			Rectangle r2 = tiburones.at(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				resultado_colision = true;
				objbuceador->retornar_flecha_enindice(i)->cambiar_eliminar(true);

				if (tiburones.at(j)->retornar_vidas() > 0)
				{
					tiburones.at(j)->cambiar_vidas(tiburones.at(j)->retornar_vidas() - 1);
				}
				if (tiburones.at(j)->retornar_vidas() == 0)
				{
					tiburones.at(j)->cambiar_eliminar(true);
				}

				objbuceador->borrar_flechas();

				for (int i = 0; i < tiburones.size(); i++)
				{
					if (tiburones.at(i)->retornar_eliminar() == true)
						tiburones.erase(tiburones.begin() + i);
				}

			}
		}
	}

	return resultado_colision;
}
bool Controladora::Colision_flechas_pajaros()
{
	bool resultado_colision = false;

	for (int i = 0; i < objbuceador->retornar_cant_flechas(); i++)
	{
		Rectangle r1 = objbuceador->retornar_flecha_enindice(i)->retornar_rectangle();
		for (int j = 0; !resultado_colision && j < pajaros.size(); j++)
		{
			Rectangle r2 = pajaros.at(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				resultado_colision = true;
				objbuceador->retornar_flecha_enindice(i)->cambiar_eliminar(true);
				pajaros.at(j)->cambiar_eliminar(true);
				bird_bonus = true;
				municion += 20;
				
				//nivel = 2; 
				
				objbuceador->borrar_flechas();

				

			}
		}

		for (int k = 0; k < pajaros.size(); k++)
		{
			if (pajaros.at(k)->retornar_eliminar() == true)
				pajaros.erase(pajaros.begin() + k);
		}
	}

	return resultado_colision;
}
Controladora::~Controladora()
{
	for (int i = 0; i < pirañas.size(); i++)
		delete pirañas.at(i);
	for (int i = 0; i < bonuses.size(); i++)
		delete bonuses.at(i);
	for (int i = 0; i < tiburones.size(); i++)
		delete tiburones.at(i);
	for (int i = 0; i < basuras.size(); i++)
		delete basuras.at(i);
	delete objbuceador;
}
void Controladora::cambiar_nivel(int nuevo) { nivel = nuevo; }
int Controladora::retornar_nivel() { return nivel; }
bool Controladora::retornar_cerrar() { return cerrar; }
bool Controladora::retornar_pasar_nivel() { return pasar_nivel; }
int Controladora::retornar_vidas() { return vidas; }
int Controladora::retornar_municion() { return municion; }
int Controladora::retornar_contador_de_basura() { return contador_basuras; }
time_t Controladora::Retornar_inicio() { return inicio; }
void Controladora::Restart_inicio() { inicio = clock(); }
void Controladora::GrabarenArchivo(vector<string> datos)
{
	objbuceador->GrabarArchivo(datos);
}
int Controladora::retornar_puntaje() { return puntaje_total; }
# 🐟 The Garbage Eater

**The Garbage Eater** es un videojuego educativo y arcade desarrollado en **C++ con Windows Forms**, sin motor gráfico, que utiliza **sprites personalizados** y lógica por eventos para crear una experiencia inmersiva de limpieza submarina.

## 🎮 Descripción del juego

Controlas a un **buceador** cuyo objetivo es limpiar el fondo marino recolectando basura mientras esquivas o enfrentas a depredadores como pirañas y tiburones. A lo largo de dos niveles progresivos, deberás recolectar una cantidad mínima de basura para completar la misión.

## ⚙️ Tecnología usada

- Lenguaje: **C++**
- Interfaz: **Windows Forms** (`/clr`)
- Sin motores gráficos externos
- Manejo de **sprites e imágenes** `.png` y efectos sonoros `.wav`
- Arquitectura modular basada en clases (`Buceador`, `Basura`, `Enemigo`, etc.)

---

## 🕹️ Controles

- Movimiento: `AWSD` o flechas (`↑ ↓ ← →`)
- Disparo: `Espacio`
- El jugador cuenta con:
  - 3 vidas
  - 5 flechas iniciales
  - 5 arpones adicionales (repartidos por el mapa)
  - Bonificaciones (velocidad y puntuación)

---

## 📜 Reglas generales

- Por cada **30 basuritas** recogidas, el buceador gana una vida extra.
- Existen **10 bonus** en el mapa que otorgan velocidad doble por 4 segundos.
- Cuando se queda con solo una flecha, aparecerá un **pájaro bonus**: si lo aciertas, ganas 20 flechas (solo una vez por partida).
- Si una flecha impacta a un enemigo, este pierde una vida.
- Si el buceador choca con un enemigo, **pierde una vida y regresa al inicio**.
- El buceador no puede salir a la superficie.
- Animales marinos también reaccionan dinámicamente al entorno.

---

## 🌊 Niveles

### Nivel 1

- Duración: **3 minutos**
- Enemigos: **6 pirañas hambrientas** (con 1 a 3 vidas cada una)
- Objetivo: **Recolectar 100 basuritas**
- Si todas las pirañas mueren, desaparecen del mapa.
- El jugador puede morir si es tocado por una piraña.

### Nivel 2

- Duración: **2 minutos**
- Enemigos: **8 tiburones asesinos** (con 1 a 3 vidas cada uno)
- Objetivo: **Recolectar 150 basuritas**
- Mayor dificultad y velocidad de los enemigos.
- El jugador puede morir si es tocado por un tiburón.

---

## 🖼️ Recursos visuales y sonoros

- Sprites personalizados (`.png`) para personajes, basura y entorno.
- Sonidos `.wav` para ambientación marina y efectos de interacción.
- Archivos de diseño (`.sln`, `.vcxproj`) incluidos.

---

## 📦 Instrucciones de compilación

> Requiere Visual Studio con soporte para C++ CLR (Windows Forms).

1. Clona el repositorio:

```bash
git clone https://github.com/MrBlueSky8/the-garbage-eater.git

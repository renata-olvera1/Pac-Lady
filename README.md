# Proyecto: Pac-Lady

## Descripción del Proyecto
Pac-Lady es un videojuego desarrollado en C++ utilizando la biblioteca SFML. El objetivo principal es guiar al personaje principal, Pac-Lady, a través de un laberinto mientras evita los obstáculos y enemigos, recolecta objetos y acumula puntos. El juego incorpora colisiones precisas basadas en el mapa, que está representado por una imagen PNG donde las paredes u obstáculos son identificados por un color específico.

## Historia del Juego
En un mundo digital donde los laberintos son infinitos, Pac-Lady es una heroína que lucha por recuperar las gemas de energía robadas por un virus malicioso. Estas gemas mantienen la estabilidad del sistema donde habita. Con cada nivel superado, el laberinto se vuelve más desafiante y los enemigos más rápidos. Ayuda a Pac-Lady a restaurar el equilibrio del sistema antes de que sea demasiado tarde.

## Manual de Usuario (Cómo Jugar)
1. **Inicio del juego**:
   - Ejecuta el archivo binario generado (ejemplo: `PacLady.exe`).
   - Usa las flechas del teclado para mover a Pac-Lady en las direcciones: arriba, abajo, izquierda y derecha.
2. **Objetivo**:
   - Recolecta los circulos mientras evitas los enemigos.
   - No te choques contra las paredes u obstáculos.
3. **Puntuación**:
   - Cada gema recolectada otorga puntos.
   - Completa el laberinto.
4. **Condiciones de derrota**:
   - Si Pac-Lady es atrapada por un enemigo el juego termina.

## Manual del Programador (Cómo Compilar el Código)
1. **Requisitos Previos**:
   - **IDE**: Visual Studio 2019 o superior.
   - **Bibliotecas**: SFML (Simple and Fast Multimedia Library) en su versión más reciente.
2. **Configuración del Proyecto**:
   - Descarga o clona el repositorio desde [GitHub](https://github.com/renata-olvera1/Pac-Lady.git).
   - Abre el archivo del proyecto `.sln` en Visual Studio.
   - Configura la ruta de las librerías y encabezados de SFML en las propiedades del proyecto.
3. **Compilación**:
   - Selecciona el modo de compilación (Debug o Release).
   - Compila el proyecto esbribe en la terminal "make runjuego"
4. **Ejecución**:
   - Una vez compilado, ejecuta el archivo generado desde Visual Studio o directamente desde el directorio `bin`.

---


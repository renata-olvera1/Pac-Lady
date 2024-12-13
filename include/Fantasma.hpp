#ifndef FANTASMAS_HPP
#define FANTASMAS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace sf;
using namespace std;

class Fantasma {
public:
    // Constructor
    Fantasma(const string &rutaImagen, float x, float y, float velocidad = 0.2f) 
    : velocidad(velocidad) {
        if (!textura.loadFromFile(rutaImagen)) {
            cout << "Error: No se pudo cargar la imagen del fantasma." << endl;
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para ajustarla

        // Inicializar el generador de números aleatorios
        srand(static_cast<unsigned int>(time(nullptr)));
        cambiarDireccion();
    }

    // Movimiento automático aleatorio
    void moverAuto(float limiteX, float limiteY) {
        Vector2f posicion = sprite.getPosition();
        if (posicion.x + direccion.x < 0 || posicion.x + direccion.x > limiteX - sprite.getGlobalBounds().width) {
            direccion.x = -direccion.x;
        }
        if (posicion.y + direccion.y < 0 || posicion.y + direccion.y > limiteY - sprite.getGlobalBounds().height) {
            direccion.y = -direccion.y;
        }
        sprite.move(direccion * velocidad);

        // Cambiar dirección periódicamente
        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            cambiarDireccion();
            clock.restart();
        }
    }

    // Dibujar al fantasma
    void dibujar(RenderWindow &ventana) {
        ventana.draw(sprite);
    }

private:
    Texture textura;      // Textura para cargar la imagen
    Sprite sprite;        // Sprite que representa al fantasma
    Vector2f direccion{1.0f, 1.0f}; // Dirección inicial de movimiento
    float velocidad;
    Clock clock;

    // Función para cambiar de dirección aleatoriamente
    void cambiarDireccion() {
        direccion.x = (rand() % 3 - 1); // -1, 0, 1
        direccion.y = (rand() % 3 - 1); // -1, 0, 1

        // Asegúrate de que el fantasma siempre se mueva
        if (direccion.x == 0 && direccion.y == 0) {
            direccion.x = 1;
        }
    }
};

#endif // FANTASMAS_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Fantasma {
public:
    // Constructor
    Fantasma(const string &rutaImagen, float x, float y, float velocidad = 0.2f) : velocidad(velocidad) {
        if (!textura.loadFromFile(rutaImagen)) {
            cout << "Error: No se pudo cargar la imagen del fantasma." << endl;
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para ajustarla
    }

    // Movimiento automático (patrón simple de movimiento)
    void moverAuto(float limiteX, float limiteY) {
        Vector2f posicion = sprite.getPosition();
        if (posicion.x + direccion.x < 0 || posicion.x + direccion.x > limiteX - sprite.getGlobalBounds().width) {
            direccion.x = -direccion.x;
        }
        if (posicion.y + direccion.y < 0 || posicion.y + direccion.y > limiteY - sprite.getGlobalBounds().height) {
            direccion.y = -direccion.y;
        }
        sprite.move(direccion * velocidad);
    }

    // Método para verificar colisiones con la línea marrón
    bool verificarColision(const Image &mapa) {
        FloatRect bounds = sprite.getGlobalBounds();
        for (int x = bounds.left; x < bounds.left + bounds.width; x++) {
            for (int y = bounds.top; y < bounds.top + bounds.height; y++) {
                // Obtén el color del píxel actual en el mapa
                Color pixelColor = mapa.getPixel(x, y);

                // Verifica si es marrón
                if (pixelColor == Color(139, 69, 19)) { // RGB para marrón
                    return true; // Colisión detectada
                }
            }
        }
        return false;
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
};


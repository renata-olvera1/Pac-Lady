#include <SFML/Graphics.hpp>
#include <string>
#include "CollisionMap.hpp"
using namespace std;
using namespace sf;

class PacLady {
public:
    PacLady(const string& rutaImagen, float x, float y, float velocidad = .5f) : velocidad(velocidad) {
        if (!textura.loadFromFile(rutaImagen)) {
            throw runtime_error("No se pudo cargar la imagen de PacLady.");
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para hacerla más pequeña
    }

    void mover(Keyboard::Key tecla, float velocidad) {
        Vector2f movimiento(0.0f, 0.0f);
        Vector2f nuevaPosicion = sprite.getPosition();

        if (tecla == Keyboard::Up) {
            movimiento.y -= velocidad;
            nuevaPosicion.y -= velocidad;
        } else if (tecla == Keyboard::Down) {
            movimiento.y += velocidad;
            nuevaPosicion.y += velocidad;
        } else if (tecla == Keyboard::Left) {
            movimiento.x -= velocidad;
            nuevaPosicion.x -= velocidad;
        } else if (tecla == Keyboard::Right) {
            movimiento.x += velocidad;
            nuevaPosicion.x += velocidad;
        }

        if (!checkCollision(nuevaPosicion.x, nuevaPosicion.y)) {
            sprite.move(movimiento);
        }
    }

    void dibujar(RenderWindow& ventana) {
        ventana.draw(sprite);
    }

    Vector2f getCenterPosition() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    }

private:
    bool checkCollision(float x, float y) {
        int gridX = static_cast<int>(x / TILE_SIZE);
        int gridY = static_cast<int>(y / TILE_SIZE);
        return collisionMap[gridY][gridX] == 1;
    }

    Texture textura;
    Sprite sprite;
    float velocidad;
};
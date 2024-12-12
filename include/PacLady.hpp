#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class PacLady {
public:
    PacLady(const string& rutaImagen, float x, float y, float velocidad = .5f) 
        : velocidad(velocidad) {
        if (!textura.loadFromFile(rutaImagen)) {
            throw runtime_error("No se pudo cargar la imagen de PacLady.");
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para hacerla más pequeña
    }

    void mover(Keyboard::Key tecla, float velocidad) {
        Vector2f movimiento(0.0f, 0.0f);

        if (tecla == Keyboard::Up) {
            movimiento.y -= velocidad;
        } else if (tecla == Keyboard::Down) {
            movimiento.y += velocidad;
        } else if (tecla == Keyboard::Left) {
            movimiento.x -= velocidad;
        } else if (tecla == Keyboard::Right) {
            movimiento.x += velocidad;
        }

        sprite.move(movimiento);
    }

    void dibujar(RenderWindow& ventana) {
        ventana.draw(sprite);
    }

    Vector2f getCenterPosition() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    }

private:
    Texture textura;
    Sprite sprite;
    float velocidad;
};
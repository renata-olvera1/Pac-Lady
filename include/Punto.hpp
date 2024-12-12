#include <SFML/Graphics.hpp>
using namespace sf;

class Punto {
public:
    Punto(float x, float y, float radio) : visible(true) {
        circulo.setRadius(radio);
        circulo.setFillColor(Color::White);
        circulo.setPosition(x - radio, y - radio); // Centrar el círculo
    }

    void dibujar(RenderWindow& ventana) {
        if (visible) {
            ventana.draw(circulo);
        }
    }

    Vector2f getPosition() const {
        return circulo.getPosition();
    }

    void setVisible(bool v) {
        visible = v;
    }

    bool isVisible() const {
        return visible;
    }

private:
    CircleShape circulo;
    bool visible;
};
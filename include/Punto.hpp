#include <SFML/Graphics.hpp>
using namespace sf;

class Punto {
    public:
    
        Punto(float x, float y, float radio) {
        circulo.setRadius(radio);
        circulo.setFillColor(Color::White);
        circulo.setPosition(x - radio, y - radio); // Centrar el círculo
    }

    void dibujar(RenderWindow& ventana) {
        ventana.draw(circulo);
    }

    private:
        CircleShape circulo;
    };
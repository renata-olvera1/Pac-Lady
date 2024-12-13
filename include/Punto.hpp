#include <SFML/Graphics.hpp>
using namespace sf;

class Punto
{
public:
    Punto(float x, float y, float radio) : visible(true)
    {
        circulo.setRadius(radio);
        circulo.setFillColor(Color::White);
        circulo.setPosition(x - radio, y - radio); // Centrar el círculo
    }

    void dibujar(RenderWindow &ventana)
    {
        if (visible)
        {
            ventana.draw(circulo);
        }
    }

    Vector2f getPosition() const
    {
        return circulo.getPosition();
    }

    void setVisible(bool v)
    {
        visible = v;
        if (!v)
        {
            reloj.restart(); // Reiniciar el reloj cuando el punto se hace invisible
        }
    }

    bool isVisible() const
    {
        return visible;
    }

    void actualizar()
    {
        if (!visible && reloj.getElapsedTime().asSeconds() >= 5)
        {
            visible = true; // Hacer visible el punto después de 5 segundos
        }
    }

private:
    CircleShape circulo;
    bool visible;
    Clock reloj;
};
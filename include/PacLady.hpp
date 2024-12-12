#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class PacLady
{
public:
    // Constructor
    PacLady(const string &rutaImagen, float x, float y, float velocidad = .5f) : velocidad(velocidad)
    {
        if (!textura.loadFromFile(rutaImagen))
        {
            cout << "Error: No se pudo cargar la imagen de PacLady." << endl;
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);

        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para hacerla más pequeña

    }

    // Mover a PacLady
    void mover(Keyboard::Key tecla, float velocidad)
    {
        sf::Vector2f movimiento(0.0f, 0.0f);

        if (tecla == Keyboard::Up)
        {
            movimiento.y -= velocidad;
        }
        else if (tecla == Keyboard::Down)
        {
            movimiento.y += velocidad;
        }
        else if (tecla == Keyboard::Left)
        {
            movimiento.x -= velocidad;
        }
        else if (tecla == Keyboard::Right)
        {
            movimiento.x += velocidad;
        }

        sprite.move(movimiento);
    }

    // Dibujar a PacLady
    void dibujar(RenderWindow &ventana)
    {
        ventana.draw(sprite);
    }

    // Obtener la posición central de PacLady
    Vector2f getCenterPosition() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    }

private:
    Texture textura; // Textura para cargar la imagen
    Sprite sprite;   // Sprite que representa a PacLady
    float velocidad;
};

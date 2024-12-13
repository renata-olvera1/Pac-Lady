#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Fantasma
{
public:
    // Constructor
    Fantasma(const string &rutaImagen, float x, float y, float velocidad = 0.2f) : velocidad(velocidad)
    {
        if (!textura.loadFromFile(rutaImagen))
        {
            cout << "Error: No se pudo cargar la imagen del fantasma." << endl;
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.05f, 0.05f); // Escalar la imagen para ajustarla
    }

    // Movimiento automático (patrón simple de movimiento)
    void moverAuto(float limiteX, float limiteY)
    {
        Vector2f posicion = sprite.getPosition();
        if (posicion.x + direccion.x < 0 || posicion.x + direccion.x > limiteX - sprite.getGlobalBounds().width)
        {
            direccion.x = -direccion.x;
        }
        if (posicion.y + direccion.y < 0 || posicion.y + direccion.y > limiteY - sprite.getGlobalBounds().height)
        {
            direccion.y = -direccion.y;
        }
        sprite.move(direccion * velocidad);
    }

    // Dibujar el fantasma en la ventana
    void dibujar(RenderWindow &ventana)
    {
        ventana.draw(sprite);
    }

    // Establecer la posición inicial del fantasma
    void setPosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    // Obtener la posición del fantasma
    Vector2f getPosition() const
    {
        return sprite.getPosition();
    }

private:
    Texture textura;
    Sprite sprite;
    Vector2f direccion = {1.0f, 1.0f}; // Dirección inicial del movimiento
    float velocidad;
};
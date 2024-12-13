#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Mapa
{
public:
    // Constructor: carga la textura y configura el sprite
    Mapa(const string &rutaImagen, float escala)
    {
        if (!texture.loadFromFile(rutaImagen))
        {
            cout << "Error: No se pudo cargar la imagen: " << rutaImagen << endl;
            exit(-1); // Salir si hay un error
        }

        // Configurar el sprite con la textura
        sprite.setTexture(texture);
        sprite.setScale(escala, escala);

        // Ajustar el origen para centrar el sprite
        Vector2u textureSize = texture.getSize();
        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    }

    // Método para centrar el sprite en la ventana
    void centrarEnVentana(Vector2u windowSize)
    {
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
    }

    // Método para dibujar el mapa
    void dibujar(RenderWindow &ventana)
    {
        ventana.draw(sprite);
    }

private:
    Texture texture; // Textura del mapa
    Sprite sprite;   // Sprite del mapa
};

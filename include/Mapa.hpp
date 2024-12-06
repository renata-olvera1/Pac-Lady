#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Mapa {
public:
    // Constructor: carga la textura y configura el sprite
    Mapa(const std::string& rutaImagen, float escala) {
        if (!texture.loadFromFile(rutaImagen)) {
            cout << "Error: No se pudo cargar la imagen: " << rutaImagen << endl;
            exit(-1); // Salir si hay un error
        }

        // Configurar el sprite con la textura
        sprite.setTexture(texture);
        sprite.setScale(escala, escala);

        // Ajustar el origen para centrar el sprite
        sf::Vector2u textureSize = texture.getSize();
        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    }

    // Método para centrar el sprite en la ventana
    void centrarEnVentana(sf::Vector2u windowSize) {
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
    }

    // Método para dibujar el mapa
    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(sprite);
    }

private:
    sf::Texture texture; // Textura del mapa
    sf::Sprite sprite;   // Sprite del mapa
};

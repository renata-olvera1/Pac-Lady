#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"
using namespace std;

int main() {
    // Crear una ventana con el tamaño de la imagen
    GameWindow window(1026, 1260, "Mapa Pac-Lady");

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("assets/images/MapaPacLady.png")) {
        cout << "Error: No se pudo cargar la imagen." << endl;
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    // Ajustar el sprite para centrarlo en la ventana
    sf::Vector2u textureSize = texture.getSize();
    sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    sprite.setPosition(1026 / 2, 1260 / 2);

    // Bucle principal
    while (window.isOpen()) {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el sprite en la ventana
        window.draw(sprite);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}

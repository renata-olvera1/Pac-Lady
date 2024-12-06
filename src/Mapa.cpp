#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"

int main() {
    // Crear la ventana
    sf::Texture texture;
    if (!texture.loadFromFile("assets/images/MapaPacLady.png")) {
        std::cout << "Error: No se pudo cargar la imagen." << std::endl;
        return -1;
    }

    sf::Vector2u textureSize = texture.getSize();
    float scaleFactor = .75f; // Escalado al 50%

    GameWindow window(textureSize.x * scaleFactor, textureSize.y * scaleFactor, "MapaPacLady");

    // Crear el sprite y asignarle la textura
    sf::Sprite sprite(texture);
    sprite.setScale(scaleFactor, scaleFactor); // Reducir el tamaño de la imagen

    // Centrar el sprite en la ventana
    sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    sprite.setPosition((textureSize.x * scaleFactor) / 2, (textureSize.y * scaleFactor) / 2);

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

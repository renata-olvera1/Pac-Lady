#include <GameWindow.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    // Crear una ventana
    GameWindow window(2000, 1500, "SFML Image");

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("assets/images/MapaPacLady.png")) // Ajusta el nombre y ruta de la imagen
    {
        // Manejar el error si no se puede cargar la imagen
        cout << "Error: No se pudo cargar la imagen." << endl;
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    // Ajustar el sprite para centrarlo en la ventana
    sf::Vector2u textureSize = texture.getSize();
    sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    sprite.setPosition(400, 300); // Centrado en una ventana de 800x600

    // Bucle principal
    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // Condición completa
            {
                // Cerrar la ventana si se recibe el evento de cerrar
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

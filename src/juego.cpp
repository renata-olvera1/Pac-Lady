#include "Mapa.hpp"
#include "GameWindow.hpp"

int main() {
    // Crear la ventana
    GameWindow window(1026, 1260, "Juego Pac-Lady");

    // Crear y configurar el mapa
    float escala = 0.5f; // Escala para reducir el tamaño del mapa
    Mapa mapa("assets/images/MapaPacLady.png", escala);

    // Centrar el mapa en la ventana
    mapa.centrarEnVentana(window.getSize());

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
        mapa.dibujar(window.getRenderWindow());

        // Mostrar la ventana
        window.display();
    }

    return 0;
}

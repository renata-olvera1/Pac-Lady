#include "Mapa.hpp"
#include "GameWindow.hpp"
#include "Punto.hpp"
#include "PacLady.hpp"
#include <vector>

int main() {

    int xorigen = 275;
    int yorigen = 609;

    // Crear la ventana
    GameWindow window(1026, 1260, "Juego Pac-Lady");

    // Crear y configurar el mapa
    float escala = 0.5f; // Escala para reducir el tamaño del mapa
    Mapa mapa("assets/images/MapaPacLady.png", escala);

    // Centrar el mapa en la ventana
    mapa.centrarEnVentana(window.getSize());

    // Crear puntos en diferentes posiciones
    vector<Punto> puntos = {
        Punto(550, 798, 5), Punto(580, 798, 5), Punto(610, 798, 5),
        Punto(485, 798, 5), Punto(455, 798, 5), Punto(425, 798, 5),
        Punto(395, 798, 5) //Punto(370, 798, 5) //Punto(500, 798, 5)
    };

    // Crear a PacLady
    PacLady pacLady("assets/images/Pac-Lady.png", xorigen, yorigen); // Cambia la ruta de la imagen

    // Bucle principal
    while (window.isOpen()) {
        // Procesar eventos

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Control de movimiento con las flechas del teclado
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            pacLady.mover(Keyboard::Up, .045f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pacLady.mover(Keyboard::Down, .045f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            pacLady.mover(Keyboard::Left, .045f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            pacLady.mover(Keyboard::Right, .045f);
        }

        // Dibujar elementos en la ventana
        window.clear();
        mapa.dibujar(window.getRenderWindow());

        // Dibujar los puntos
        for (auto &punto : puntos) {
            punto.dibujar(window.getRenderWindow());
        }

        /*for (auto& punto : puntos) {
            punto.dibujar(window.getRenderWindow());
        }*/

        pacLady.dibujar(window.getRenderWindow());
        window.display();
    }

    return 0;
}

#include "Mapa.hpp"
#include "GameWindow.hpp"
//#include "Punto.hpp"
#include <PacLady.hpp>
#include <vector>

int main() {
    // Crear la ventana
    GameWindow window(1026, 1260, "Juego Pac-Lady");

    // Crear y configurar el mapa
    float escala = 0.5f; // Escala para reducir el tamaño del mapa
    Mapa mapa("assets/images/MapaPacLady.png", escala);

    // Centrar el mapa en la ventana
    mapa.centrarEnVentana(window.getSize());

    // Crear puntos en diferentes posiciones
    /*
    vector<Punto> puntos = {
        Punto(200, 150, 5.0), Punto(300, 150, 5.0), Punto(400, 150, 5.0),
        Punto(200, 250, 5.0), Punto(300, 250, 5.0), Punto(400, 250, 5.0),
        Punto(200, 350, 5.0), Punto(300, 350, 5.0), Punto(400, 350, 5.0)
    };*/

    // Crear a PacLady
    PacLady pacLady("assets/images/Pac-Lady.png", 400, 300); // Cambia la ruta de la imagen

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
            pacLady.mover(Keyboard::Up, 5.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pacLady.mover(Keyboard::Down, 5.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            pacLady.mover(Keyboard::Left, 5.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            pacLady.mover(Keyboard::Right, 5.0f);
        }

        // Dibujar elementos en la ventana
        window.clear();
        mapa.dibujar(window.getRenderWindow());

        /*for (auto& punto : puntos) {
            punto.dibujar(window.getRenderWindow());
        }*/

        pacLady.dibujar(window.getRenderWindow());
        window.display();
    }

    return 0;
}

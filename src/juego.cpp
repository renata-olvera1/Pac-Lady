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

    // Puntos Linea A
    vector<Punto> Linea_A = {
        Punto(545, 798, 4), Punto(575, 798, 4), Punto(605, 798, 4), 
        Punto (630, 798, 4), Punto(485, 798, 4), Punto(455, 798, 4),
        Punto(425, 798, 4), Punto(395, 798, 4)
    };

    // Puntos Linea B
    vector<Punto> Linea_B = {
        Punto(395, 768, 4), Punto(395, 708, 4), Punto(395, 408, 4),
        Punto(395, 678, 4), Punto(395, 648, 4), Punto(395, 618, 4),
        Punto(395, 588, 4), Punto(395, 558, 4), Punto(395, 528, 4),
        Punto(395, 498, 4), Punto(395, 468, 4), Punto(395, 438, 4),
        Punto(395, 378, 4), Punto(395, 828, 4), Punto(395, 850, 4),
    };

    //vector<Punto> Linea_C = {

    //};

    vector<Punto> Linea_J = {
        Punto(355, 748, 4), Punto(330, 748, 4), Punto(305, 748, 4),
        Punto(305, 773, 4), Punto(305, 795, 4), Punto(330, 795, 4),
        Punto(355, 795, 4), Punto(380, 748, 4), Punto(355, 828, 4),
        Punto(355, 863, 4), Punto(380, 863, 4), Punto(330, 863, 4),
        Punto(305, 863, 4)
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

        // Dibujar lineas de puntos
        for (auto &punto : Linea_A) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_B) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_C) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_J) {
            punto.dibujar(window.getRenderWindow());
        }

        pacLady.dibujar(window.getRenderWindow());
        window.display();
    }

    return 0;
}

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

    // Puntos Linea C
    vector<Punto> Linea_C = {
        Punto(425, 748, 4), Punto(455, 748, 4), Punto(485, 748, 4),
        Punto(485, 773, 4), Punto(440, 713, 4), Punto(440, 683, 4),
    };

    // Puntos Linea D
    vector<Punto> Linea_D = {
        Punto(440, 818, 4), Punto(440, 843, 4), Punto(440, 868, 4),
        Punto(465, 868, 4), Punto(490, 868, 4), Punto(490, 893, 4)
    };

    // Puntos Linea E
    vector<Punto> Linea_E = {
        Punto(630, 768, 4), Punto(630, 708, 4), Punto(630, 408, 4),
        Punto(630, 678, 4), Punto(630, 648, 4), Punto(630, 618, 4),
        Punto(630, 588, 4), Punto(630, 738, 4), Punto(630, 528, 4),
        Punto(630, 498, 4), Punto(630, 468, 4), Punto(630, 438, 4),
        Punto(630, 378, 4), Punto(630, 828, 4), Punto(630, 850, 4),
    };

    // Puntos Linea F

    vector<Punto> Linea_F{
        Punto(605, 748, 4), Punto(575, 748, 4), Punto(545, 748, 4),
        Punto(545, 773, 4), Punto(585, 713, 4), Punto(585, 683, 4),
    };

    // Puntos Linea G
    vector<Punto> Linea_G{
        Punto(585, 818, 4), Punto(585, 843, 4), Punto(585, 868, 4),
        Punto(565, 868, 4), Punto(540, 868, 4), Punto(540, 893, 4)
    };

    // Puntos Linea H
    vector<Punto> Linea_H{
        Punto(305, 913, 4), Punto(330, 913, 4), Punto(355, 913, 4),
        Punto(380, 913, 4), Punto(410, 913, 4), Punto(440, 913, 4),
        Punto(465, 913, 4), Punto(490, 913, 4), Punto(515, 913, 4),
        Punto(540, 913, 4), Punto(565, 913, 4), Punto(590, 913, 4),
        Punto(620, 913, 4), Punto(675, 913, 4), Punto(700, 913, 4),
        Punto(725, 913, 4)
    };

    // Puntos Linea I
    vector<Punto> Linea_I{
        Punto(467, 683, 4), Punto(497, 683, 4), Punto(527, 683, 4),
        Punto(557, 683, 4)
    };

    // Puntos Linea J
    vector<Punto> Linea_J = {
        Punto(355, 748, 4), Punto(330, 748, 4), Punto(305, 748, 4),
        Punto(305, 773, 4), Punto(305, 795, 4), Punto(330, 795, 4),
        Punto(355, 795, 4), Punto(380, 748, 4), Punto(355, 828, 4),
        Punto(355, 863, 4), Punto(380, 863, 4), Punto(330, 863, 4),
        Punto(305, 863, 4)
    };

    // Puntos Linea K
    vector<Punto> Linea_K = {
        Punto(650, 748, 4), Punto(675, 748, 4), Punto(700, 748, 4),
        Punto(725, 748, 4), Punto(725, 773, 4), Punto(725, 795, 4), 
        Punto(700, 795, 4), Punto(675, 828, 4), Punto(675, 863, 4), 
        Punto(650, 863, 4), Punto(700, 863, 4), Punto(725, 863, 4), 
        Punto(725, 893, 4),
    };

    // Puntos Linea L
    vector<Punto> Linea_L = {
        Punto(540, 348, 4), Punto(570, 348, 4), Punto(601, 348, 4),
        Punto(632, 348, 4), Punto(663, 348, 4), Punto(694, 348, 4),
        Punto(725, 348, 4)
    };

    // Puntos Linea M
    vector<Punto> Linea_M = {
        Punto(490, 348, 4), Punto(460, 348, 4), Punto(429, 348, 4),
        Punto(398, 348, 4), Punto(336, 348, 4), Punto(305, 348, 4)   
    };

    // Puntos Linea N
    vector<Punto> Linea_N = {
        Punto(305, 378, 4), Punto(305, 408, 4), Punto(305, 438, 4),
        Punto(305, 463, 4), Punto(305, 488, 4), Punto(305, 513, 4),
        Punto(336, 513, 4), Punto(367, 513, 4), Punto(336, 438, 4),
        Punto(367, 438, 4)
    };

    // Puntos Linea Ñ
    vector<Punto> Linea_NN{
        Punto(725, 378, 4), Punto(725, 408, 4), Punto(725, 438, 4),
        Punto(725, 463, 4), Punto(725, 488, 4), Punto(725, 513, 4),
        Punto(663, 513, 4), Punto(694, 513, 4), Punto(663, 438, 4),
    };

    // Puntos Linea O
    vector<Punto> Linea_O = {
        Punto(540, 378, 4), Punto(540, 408, 4)
    };

    // Puntos Linea P
    vector<Punto> Linea_P = {
        Punto(490, 378, 4), Punto(490, 408, 4)
    };

    // Puntos Linea Q
    vector<Punto> Linea_Q = {
        Punto(490, 438, 4), Punto(515, 438, 4), Punto(540, 438, 4),
        Punto(570, 438, 4), Punto(600, 438, 4), Punto(460, 438, 4),
        Punto(430, 438, 4)
    };

    // Puntos Linea R
    vector<Punto> Linea_R = {
        Punto(445, 468, 4), Punto(455, 518, 4), Punto(485, 518, 4),
    };

    // Puntos Linea S
    vector<Punto> Linea_S = {
        Punto(585, 468, 4), Punto(585, 498, 4), Punto(575, 518, 4),
        Punto(545, 518, 4)
    };

    // Puntos Linea T
    vector<Punto> Linea_T = {
        Punto(440, 653, 4), 
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

        for (auto &punto : Linea_D) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_E) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_F) {
            punto.dibujar(window.getRenderWindow());
        }
        
        for (auto &punto : Linea_G) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_H) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_I) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_J) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_K) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_L) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_M) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_N) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_NN) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_O) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_P) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_Q) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_R) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_S) {
            punto.dibujar(window.getRenderWindow());
        }

        for (auto &punto : Linea_T) {
            punto.dibujar(window.getRenderWindow());
        }

        pacLady.dibujar(window.getRenderWindow());
        window.display();
    }

    return 0;
}

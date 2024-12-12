#include <SFML/Graphics.hpp>
#include <string>

class Puntaje {
public:
    Puntaje(const std::string& fontPath) : puntaje(0) {
        if (!fuente.loadFromFile(fontPath)) {
            throw std::runtime_error("No se pudo cargar la fuente");
        }
        texto.setFont(fuente);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(10, 10);
        actualizarTexto();
    }

    void aumentar() {
        puntaje++;
        actualizarTexto();
    }

    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(texto);
    }

    int obtenerPuntaje() const {
        return puntaje;
    }

private:
    void actualizarTexto() {
        texto.setString("Puntaje: " + std::to_string(puntaje));
    }

    int puntaje;
    sf::Font fuente;
    sf::Text texto;
};
#include <SFML/Graphics.hpp>
#include <string>

class Puntaje {
public:
    Puntaje(const std::string& fontPath, const std::string& imagePath) : puntaje(0) {
        if (!fuente.loadFromFile(fontPath)) {
            throw std::runtime_error("No se pudo cargar la fuente");
        }
        texto.setFont(fuente);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(10, 10);
        actualizarTexto();

        if (!textura.loadFromFile(imagePath)) {
            throw std::runtime_error("No se pudo cargar la imagen");
        }
        sprite.setTexture(textura);
    }

    void aumentar() {
        puntaje++;
        actualizarTexto();
    }

    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(texto);
        ventana.draw(sprite);
    }

    int obtenerPuntaje() const {
        return puntaje;
    }

    void setImageSize(float width, float height) {
        sprite.setScale(width / sprite.getLocalBounds().width, height / sprite.getLocalBounds().height);
    }

    void setImagePosition(float x, float y) {
        sprite.setPosition(x, y);
    }

private:
    void actualizarTexto() {
        texto.setString("Puntaje: " + std::to_string(puntaje));
    }

    int puntaje;
    sf::Font fuente;
    sf::Text texto;
    sf::Texture textura;
    sf::Sprite sprite;
};
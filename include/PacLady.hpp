#include <SFML/Graphics.hpp>

class PacLady {
public:
    PacLady(const std::string& rutaImagen, float x, float y, float velocidad = .5f) 
        : velocidad(velocidad), origenX(x), origenY(y) {
        if (!textura.loadFromFile(rutaImagen)) {
            throw std::runtime_error("No se pudo cargar la imagen de PacLady.");
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para hacerla más pequeña
    }

    void mover(sf::Keyboard::Key tecla, float velocidad) {
        sf::Vector2f movimiento(0.0f, 0.0f);
        sf::Vector2f nuevaPosicion = sprite.getPosition();

        if (tecla == sf::Keyboard::Up) {
            movimiento.y -= velocidad;
            nuevaPosicion.y -= velocidad;
        } else if (tecla == sf::Keyboard::Down) {
            movimiento.y += velocidad;
            nuevaPosicion.y += velocidad;
        } else if (tecla == sf::Keyboard::Left) {
            movimiento.x -= velocidad;
            nuevaPosicion.x -= velocidad;
        } else if (tecla == sf::Keyboard::Right) {
            movimiento.x += velocidad;
            nuevaPosicion.x += velocidad;
        }

        // Verificar si PacLady está en la coordenada específica
        if (static_cast<int>(nuevaPosicion.x) == static_cast<int>(coordenadaEspecificaX) && 
            static_cast<int>(nuevaPosicion.y) == static_cast<int>(coordenadaEspecificaY)) {
            restablecerPosicion();
        }
    }

    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(sprite);
    }

    sf::Vector2f getCenterPosition() const {
        sf::FloatRect bounds = sprite.getGlobalBounds();
        return sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    }

    void setCoordenadaEspecifica(float x, float y) {
        coordenadaEspecificaX = x;
        coordenadaEspecificaY = y;
    }

private:
    
    void restablecerPosicion() {
        sprite.setPosition(origenX, origenY);
    }

    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    float origenX = 725, origenY = 609;
    float coordenadaEspecificaX, coordenadaEspecificaY;
};
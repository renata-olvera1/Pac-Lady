#include <SFML/Graphics.hpp>
#include <string>
#include "CollisionMapa.hpp"
using namespace std;
using namespace sf;

class PacLady {
public:
    PacLady(const string& rutaImagen, float x, float y, float velocidad = .5f) : velocidad(velocidad) {
        if (!textura.loadFromFile(rutaImagen)) {
            throw runtime_error("No se pudo cargar la imagen de PacLady.");
        }
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f); // Escalar la imagen para hacerla más pequeña
    }

    void mover(Keyboard::Key tecla) {
        Vector2f movimiento(0.0f, 0.0f);
        Vector2f nuevaPosicion = sprite.getPosition();

        if (tecla == Keyboard::Up) {
            movimiento.y -= velocidad;
            nuevaPosicion.y -= velocidad;
        } else if (tecla == Keyboard::Down) {
            movimiento.y += velocidad;
            nuevaPosicion.y += velocidad;
        } else if (tecla == Keyboard::Left) {
            movimiento.x -= velocidad;
            nuevaPosicion.x -= velocidad;
        } else if (tecla == Keyboard::Right) {
            movimiento.x += velocidad;
            nuevaPosicion.x += velocidad;
        }

        // Verificar colisión antes de mover
        if (!checkCollision(nuevaPosicion.x, nuevaPosicion.y)) {
            sprite.move(movimiento);
        }
    }

    void dibujar(RenderWindow& ventana) {
        ventana.draw(sprite);
    }

    Vector2f getCenterPosition() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    }

    // Método para establecer el mapa de colisiones (imagen de mapa)
    void setCollisionMap(const Image& mapaColisiones) {
        mapaColisiones = mapaColisiones; // Guardar el mapa de colisiones
    }

private:
    bool checkCollision(float x, float y) {
        // Obtener las coordenadas del píxel de la nueva posición
        int gridX = static_cast<int>(x / TILE_SIZE); // Dividir por el tamaño de cada "tile"
        int gridY = static_cast<int>(y / TILE_SIZE);

        // Verificar si la coordenada está dentro de los límites del mapa
        if (gridX < 0 || gridY < 0 || gridX >= mapaColisiones.getSize().x || gridY >= mapaColisiones.getSize().y) {
            return true; // Fuera del mapa, considera que hay colisión
        }

        // Obtener el color del píxel en esa posición
        Color pixelColor = mapaColisiones.getPixel(gridX, gridY);
        
        // Verificar si el color es el color de la pared (color café oscuro)
        return pixelColor == Color(101, 67, 33); // Compara con el color de las paredes
    }

    Texture textura;
    Sprite sprite;
    float velocidad;
    Image mapaColisiones; // Variable para almacenar el mapa de colisiones
};

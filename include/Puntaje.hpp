#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class Puntaje {
public:
    Puntaje(const string& fontPath, const string& imagePath) : puntaje(0) {
        if (!fuente.loadFromFile(fontPath)) {
            throw runtime_error("No se pudo cargar la fuente");
        }
        texto.setFont(fuente);
        texto.setCharacterSize(50); // Tamaño de texto por defecto
        texto.setFillColor(Color::White);
        texto.setPosition(10, 10); // Posición por defecto
        actualizarTexto();

        if (!textura.loadFromFile(imagePath)) {
            throw runtime_error("No se pudo cargar la imagen");
        }
        sprite.setTexture(textura);
    }

    void aumentar() {
        puntaje++;
        actualizarTexto();
    }

    void dibujar(RenderWindow& ventana) {
        ventana.draw(sprite);
        ventana.draw(texto);
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

    void setTextSize(unsigned int size) {
        texto.setCharacterSize(size);
    }

    void setTextPosition(float x, float y) {
        texto.setPosition(x, y);
    }

    void setTextString(const std::string& str) {
        texto.setString(str);
    }

private:
    void actualizarTexto() {
        texto.setString("Puntaje: " + std::to_string(puntaje));
    }

    int puntaje;
    Font fuente;
    Text texto;
    Texture textura;
    Sprite sprite;
};
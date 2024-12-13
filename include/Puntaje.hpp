#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Puntaje {
public:
    Puntaje(const string &rutaFuente, const string &rutaImagen) {
        if (!fuente.loadFromFile(rutaFuente)) {
            throw runtime_error("No se pudo cargar la fuente.");
        }
        if (!textura.loadFromFile(rutaImagen)) {
            throw runtime_error("No se pudo cargar la imagen.");
        }
        texto.setFont(fuente);
        texto.setCharacterSize(24);
        texto.setFillColor(Color::White);
        sprite.setTexture(textura);
        puntaje = 0;
        actualizarTexto();
    }

    void aumentar() {
        puntaje++;
        actualizarTexto();
    }

    void dibujar(RenderWindow &ventana) {
        ventana.draw(sprite);
        ventana.draw(texto);
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

    void setTextString(const string &str) {
        texto.setString(str);
    }

    int obtenerPuntaje() const {
        return puntaje;
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
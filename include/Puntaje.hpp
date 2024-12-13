#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Puntaje
{
public:
<<<<<<< HEAD
    Puntaje(const string &fontPath, const string &imagePath) : puntaje(0)
    {
        if (!fuente.loadFromFile(fontPath))
        {
            throw runtime_error("No se pudo cargar la fuente");
=======
    Puntaje(const string &rutaFuente, const string &rutaImagen) {
        if (!fuente.loadFromFile(rutaFuente)) {
            throw runtime_error("No se pudo cargar la fuente.");
        }
        if (!textura.loadFromFile(rutaImagen)) {
            throw runtime_error("No se pudo cargar la imagen.");
>>>>>>> 0e858438ddaf1efa416e89bedfe3dcbddfe17865
        }
        texto.setFont(fuente);
        texto.setCharacterSize(24);
        texto.setFillColor(Color::White);
<<<<<<< HEAD
        texto.setPosition(10, 10); // Posición por defecto
        actualizarTexto();

        if (!textura.loadFromFile(imagePath))
        {
            throw runtime_error("No se pudo cargar la imagen");
        }
=======
>>>>>>> 0e858438ddaf1efa416e89bedfe3dcbddfe17865
        sprite.setTexture(textura);
        puntaje = 0;
        actualizarTexto();
    }

    void aumentar()
    {
        puntaje++;
        actualizarTexto();
    }

<<<<<<< HEAD
    void dibujar(RenderWindow &ventana)
    {
=======
    void dibujar(RenderWindow &ventana) {
>>>>>>> 0e858438ddaf1efa416e89bedfe3dcbddfe17865
        ventana.draw(sprite);
        ventana.draw(texto);
    }

<<<<<<< HEAD
    int obtenerPuntaje() const
    {
        return puntaje;
    }

    void setImageSize(float width, float height)
    {
=======
    void setImageSize(float width, float height) {
>>>>>>> 0e858438ddaf1efa416e89bedfe3dcbddfe17865
        sprite.setScale(width / sprite.getLocalBounds().width, height / sprite.getLocalBounds().height);
    }

    void setImagePosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    void setTextSize(unsigned int size)
    {
        texto.setCharacterSize(size);
    }

    void setTextPosition(float x, float y)
    {
        texto.setPosition(x, y);
    }

<<<<<<< HEAD
    void setTextString(const std::string &str)
    {
=======
    void setTextString(const string &str) {
>>>>>>> 0e858438ddaf1efa416e89bedfe3dcbddfe17865
        texto.setString(str);
    }

    int obtenerPuntaje() const {
        return puntaje;
    }

private:
    void actualizarTexto()
    {
        texto.setString("Puntaje: " + std::to_string(puntaje));
    }

    int puntaje;
    Font fuente;
    Text texto;
    Texture textura;
    Sprite sprite;
};
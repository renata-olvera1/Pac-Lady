#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Vida {
public:
    Vida(const string &rutaMarco, const string &rutaCorazon, float xMarco, float yMarco, float xCorazon, float yCorazon, int numCorazones) {
        if (!texturaMarco.loadFromFile(rutaMarco)) {
            cout << "Error: No se pudo cargar la imagen del marco." << endl;
        }
        if (!texturaCorazon.loadFromFile(rutaCorazon)) {
            cout << "Error: No se pudo cargar la imagen del corazón." << endl;
        }

        spriteMarco.setTexture(texturaMarco);
        spriteMarco.setPosition(xMarco, yMarco);

        for (int i = 0; i < numCorazones; ++i) {
            Sprite corazon;
            corazon.setTexture(texturaCorazon);
            corazon.setPosition(calcularPosicionCorazon(xCorazon, i), yCorazon);
            corazones.push_back(corazon);
        }
    }

    void dibujar(RenderWindow &ventana) {
        ventana.draw(spriteMarco);
        for (const auto &corazon : corazones) {
            ventana.draw(corazon);
        }
    }

    void eliminarCorazon() {
        if (!corazones.empty()) {
            corazones.pop_back();
        }
    }

    bool sinCorazones() const {
        return corazones.empty();
    }

private:
    float calcularPosicionCorazon(float xInicial, int indice) const {
        return xInicial + indice * (texturaCorazon.getSize().x + 10); // Ajusta el espacio entre corazones
    }

    Texture texturaMarco;
    Texture texturaCorazon;
    Sprite spriteMarco;
    vector<Sprite> corazones;
};
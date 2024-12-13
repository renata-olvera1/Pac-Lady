#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Vida {
public:
    Vida(const string &rutaCorazon, float xCorazon, float yCorazon, int numCorazones, float escala = 0.03f) {
        if (!texturaCorazon.loadFromFile(rutaCorazon)) {
            cout << "Error: No se pudo cargar la imagen del corazón." << endl;
        }

        for (int i = 0; i < numCorazones; ++i) {
            Sprite corazon;
            corazon.setTexture(texturaCorazon);
            corazon.setScale(escala, escala); // Ajustar la escala del corazón
            corazon.setPosition(calcularPosicionCorazon(xCorazon, i, escala), yCorazon);
            corazones.push_back(corazon);
        }
    }

    void dibujar(RenderWindow &ventana) {
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
    float calcularPosicionCorazon(float xInicial, int indice, float escala) const {
        return xInicial + indice * (texturaCorazon.getSize().x * escala + 10); // Ajusta el espacio entre corazones
    }

    Texture texturaCorazon;
    vector<Sprite> corazones;
};
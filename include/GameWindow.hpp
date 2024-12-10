#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
using namespace sf;


class GameWindow {
public:
    GameWindow(int width, int height, const string& title) {
        window.create(VideoMode(width, height), title);
    }

    bool isOpen() {
        return window.isOpen();
    }

    void close() {
        window.close();
    }

    void clear() {
        window.clear();
    }

    void display() {
        window.display();
    }

    // Método modificado para aceptar cualquier objeto sf::Drawable
    void draw(const Drawable& drawable) {
        window.draw(drawable);
    }

    bool pollEvent(Event& event) {
        return window.pollEvent(event);
    }

    Vector2u getSize() {
        return window.getSize();
    }

    // Método para obtener la referencia a la ventana
    RenderWindow& getRenderWindow() {
        return window;
    }

private:
    RenderWindow window;
};

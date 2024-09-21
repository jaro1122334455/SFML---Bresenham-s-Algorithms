#include <SFML/Graphics.hpp>
#include "../headers/Block.h"
// #include "Field.h"

int main() {
    // Tworzymy okno o rozmiarze 800x600 pikseli i tytule "SFML Window"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // // Tworzymy kwadrat o wymiarach 100x100 pikseli
    // sf::RectangleShape square(sf::Vector2f(100.0f, 100.0f));
    // square.setFillColor(sf::Color::Red);  // Ustawiamy kolor wypełnienia na czerwony
    // square.setPosition(350.0f, 250.0f);   // Ustawiamy pozycję kwadratu na środku okna

    Block b1(50, 50, 50, 50);


    // Główna pętla programu
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Zamykamy okno, gdy użytkownik je zamknie
            }
        }

        window.clear();  // Czyszczenie ekranu
        window.draw(b1);  // Rysujemy kwadrat
        window.display();  // Wyświetlamy zawartość na ekranie
    }

    return 0;
}


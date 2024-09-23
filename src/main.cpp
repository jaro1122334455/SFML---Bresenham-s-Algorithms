#include <SFML/Graphics.hpp>
#include "../headers/Block.h"
#include "../headers/Board.h"
#include <vector>
#include <iostream>
// #include "Field.h"

const int W = 500;
const int H = 500;
int blockSize = 10;

int main() {
    // Tworzymy okno o rozmiarze 800x600 pikseli i tytule "SFML Window"
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML Window");

    // // Tworzymy kwadrat o wymiarach 100x100 pikseli
    // sf::RectangleShape square(sf::Vector2f(100.0f, 100.0f));
    // square.setFillColor(sf::Color::Red);  // Ustawiamy kolor wypełnienia na czerwony
    // square.setPosition(350.0f, 250.0f);   // Ustawiamy pozycję kwadratu na środku okna

    

    const int x = W;  // szerokość
    const int y = H;   // wysokość

    Board Bo1(W,H,blockSize);

    Board* B2 = new Board(W,H,blockSize); 

    // window.draw(Bo1);

    // delete(&Bo1);


    // Główna pętla programu
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Zamykamy okno, gdy użytkownik je zamknie
            }
        }

        window.clear();  // Czyszczenie ekranu

        if(B2 != NULL)
        {
            window.draw(*B2);

            delete(B2);

            B2 = NULL;
        }

        window.display();  // Wyświetlamy zawartość na ekranie
    }

    return 0;
}


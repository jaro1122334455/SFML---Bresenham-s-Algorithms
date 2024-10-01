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

    const int x = W;  // szerokość
    const int y = H;   // wysokość

    Board* B2 = new Board(50,50,blockSize); 

    // B2->drawCircle(24, 24 , 23);

    B2->drawLine(2,2, 43, 17);


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

            // delete(B2);

            // B2 = NULL;
        }

        window.display();  // Wyświetlamy zawartość na ekranie
    }

    return 0;
}


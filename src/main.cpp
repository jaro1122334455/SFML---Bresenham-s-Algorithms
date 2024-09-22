#include <SFML/Graphics.hpp>
#include "../headers/Block.h"
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

    // Block b1(0, 0, blockSize, blockSize);

    // Block plansza[x][y];

    Block** plansza = new Block*[x];

    for (int i = 0; i < x; ++i) {
        plansza[i] = new Block[y];
    }


    for(int i = 0; i < x; i = i + blockSize)
    {
        for(int j = 0; j < y; j = j + blockSize)
        {
            // Block b1(i, j, blockSize, blockSize);

            // std::cout << "i: " << i << " j: " << j << std::endl;

            plansza[i][j] = Block(i, j, blockSize, blockSize);
            // plansza.emplace_back((j) * (blockSize), (i) * (blockSize), blockSize, blockSize); 
        }
    }

    // int a = 0 + 90;
    // int b = 0;

    // // // Block b1(a, b, blockSize, blockSize);
    // plansza[0][0] = Block(0, 0, blockSize, blockSize);
    // plansza[90][0] = Block(90, 0, blockSize, blockSize);
    // plansza[a][b] = Block(a, b, blockSize, blockSize);


    // for(int i = 0; i < (H/blockSize); i++)                         //rysowanie planszy
    // {
    //     for(int j = 0; j < (W/blockSize); j++)
    //     {
    //         blocks.emplace_back((j) * (blockSize), (i) * (blockSize), blockSize, blockSize);                                            //Funkcja przyjmuje funkcje konstruktora
    //     }
    // }

    plansza[20][20].setFillColor(sf::Color::Red);

    // blocks[225].setFillColor(sf::Color::Red);


    // Główna pętla programu
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Zamykamy okno, gdy użytkownik je zamknie
            }
        }

        window.clear();  // Czyszczenie ekranu
        // window.draw(b1);  // Rysujemy kwadrat
        // for(auto& block : blocks)
        // {
        //     window.draw(block);
        // }

        // for(auto& block : plansza)
        // {
        //     window.draw(block);
        // }

        // window.draw(plansza[0][0]);
        // window.draw(plansza[90][0]);
        // window.draw(plansza[a][b]);

    for(int i = 0; i < x; i = i + blockSize)
    {
        for(int j = 0; j < y; j = j + blockSize)
        {
            // Block b1(i, j, blockSize, blockSize);

            // std::cout << "i: " << i << " j: " << j << std::endl;

            // plansza[i][j] = Block(i, j, blockSize, blockSize);
            window.draw(plansza[i][j]);
            // plansza.emplace_back((j) * (blockSize), (i) * (blockSize), blockSize, blockSize); 
        }
    }


        window.display();  // Wyświetlamy zawartość na ekranie
    }

    return 0;
}


#include "../headers/Board.h"
#include "../headers/Block.h"
#include <iostream>

Board::Board(int x, int y, int blckSize)
{
    this->x = x;
    this->y = y;
    this->blckSize = blckSize;

    grid = new Block*[x];

    for (int i = 0; i < x; ++i) {
        grid[i] = new Block[y];
    }

    for(int i = 0; i < x; i = i + blckSize)
    {
        for(int j = 0; j < y; j = j + blckSize)
        {
            grid[i][j] = Block(i, j, blckSize, blckSize);
        }
    }

}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    for(int i = 0; i < x; i = i + blckSize)
    {
        for(int j = 0; j < y; j = j + blckSize)
        {
            target.draw(grid[i][j]);
        }
    }
}

Board::~Board()
{
    std::cout << "Destruktor" << std::endl;

    // Usunięcie dynamicznie alokowanej pamięci dla grid
    for (int i = 0; i < x; ++i) {
        delete[] grid[i];  // usunięcie każdego wiersza (tablicy obiektów Block)
    }

    delete[] grid;  // usunięcie tablicy wskaźników

    grid = nullptr;  // ustawienie wskaźnika na null dla bezpieczeństwa
}
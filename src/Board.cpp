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

void Board::putPixel(int x, int y)
{
    std::cout << "putPixel on: " << x << " : " << y << std::endl;
    grid[x][y].getShape().setFillColor(sf::Color::Red);
}

void Board::drawCircle(int cx, int cy, int r)
{
    int x = 0;
    int y = -r;

    // putPixel(200, 200);

    while(x < -y)
    {
        int yMid = y + 5;

        if( (x*x) + (yMid * yMid) > (r * r))
        {
            y = y + 10;
        }

        putPixel(cx + x, cy + y);
        putPixel(cx - x, cy + y);
        putPixel(cx + x, cy - y);
        putPixel(cx - x, cy - y);

        putPixel(cx + y, cy + x);
        putPixel(cx + y, cy - x);
        putPixel(cx - y, cy + x);
        putPixel(cx - y, cy - x);
        x = x + 10;

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
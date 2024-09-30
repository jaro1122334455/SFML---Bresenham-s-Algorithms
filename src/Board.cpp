#include "../headers/Board.h"
#include "../headers/Block.h"
#include <iostream>
#include <cmath>

Board::Board(int x, int y, int blckSize)
{
    // sprawdzić czy zrobić tu dzielenie wszystkiego prze blckSize, żeby robić mniejsze tablice
    this->x = x * blckSize;
    this->y = y * blckSize;
    this->blckSize = blckSize;

    std::cout << "x = " << x << " y = " << y << std::endl;

    std::cout << "this x = " << this->x << " this y = " << this->y << std::endl;

    grid = new Block*[x];

    for (int i = 0; i < x; i = i + 1) {
        std::cout << "Utworzono tablice na: " << i << " pozycji, na: " << y << " elementow" << std:: endl; 
        grid[i] = new Block[y];
    }

    for(int i = 0; i < x; i = i + 1)
    {
        for(int j = 0; j < y; j = j + 1)
        {
            std::cout << "Utworzono blok na: " << i << " : " << j << std::endl;
            grid[i][j] = Block(i , j, blckSize, blckSize);
        }
    }

    this->x = x / blckSize;
    this->y = y / blckSize;

}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{

    for(int i = 0; i < x - 1; i = i + 1)
    {
        for(int j = 0; j < y - 20; j = j + 1)
        {
            std::cout << "y = " << y << std::endl;
            std::cout << "Narysowano blok na: " << i << " : " << j << std::endl;
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
        int yMid = y + (blckSize / 2);

        if( (x*x) + (yMid * yMid) > (r * r))
        {
            y = y + blckSize;
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

void Board::drawLine(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;                                       // obliczanie przesunięcia, czyli boków trójkąta który powstaje

    if(dx != 0)
    {
        float m = (float)dy / dx;                                  // obliczanie pochylenia linii (ile komórek y przesuwamy się w dół na każdą komórkę x)

        std::cout << "dx: " << dx << std::endl;
        std::cout << "dy: " << dy << std::endl;


        std::cout << "m: " << m << std::endl;

        for(int i = 0; i < dx + blckSize; i = i + blckSize)        // iteracaj po całej długości linii 
        {
            putPixel(x0 + i, round(y0 + (i / blckSize * m)) * blckSize);
            // putPixel(x0 + i, y0 + (i * m));
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
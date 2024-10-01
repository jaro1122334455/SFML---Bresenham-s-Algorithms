#pragma once
#include <SFML/Graphics.hpp>
#include "../headers/Block.h"

class Board : public sf::Drawable
{
    private:
    int x;
    int y;
    int blckSize;

    Block** grid;


    public:
    Board(){};
    Board(int x, int y, int size);

    void putPixel(int x, int y);
    void drawCircle(int cx, int cy, int r);
    void drawLine(int x0, int y0, int x1, int y1);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
    
    ~Board();
    
};

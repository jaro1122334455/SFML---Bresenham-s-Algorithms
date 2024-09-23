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

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
    
    ~Board();
    
};

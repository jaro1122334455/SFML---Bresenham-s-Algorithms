#include "../headers/Block.h"
#include <iostream>
// #include "Block.h"

Block::Block(float x, float y, float width, float height)
{
    blockX = x;
    blockY = y;

    position.x = blockX;
    position.y = blockY;

    shape.setPosition(position);
    shape.setSize(sf::Vector2f{width, height});
    // shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(-0.5);
    shape.setOutlineColor(sf::Color::Black);
}

// void Block::putPixel()
// {
//     shape.setFillColor(sf::Color::Red);
// }

void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    target.draw(this->shape, state);
}

sf::RectangleShape& Block::getShape()
{
    return this->shape;
}
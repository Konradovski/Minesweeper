//
// Created by Konrad on 07.04.2022.
//

#ifndef MINESWEEPERBOARD_CPP_MSSFMLVIEW_H
#define MINESWEEPERBOARD_CPP_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class MSSFMLView
{

    MinesweeperBoard & board;
    sf::Font font;


    void Number(sf::RenderWindow & win, char number, int width, int height, int size);
    void STATUS(sf::RenderWindow& win);
    void set_size_sq(int, int );
    sf::RectangleShape r(int width, int height);
    int scr_height;
    int scr_width;
    int size_sq;



public:
    int set_scale(sf::RenderWindow & win);
    explicit MSSFMLView(MinesweeperBoard & b);
    void draw (sf::RenderWindow & win);
    int set_offset_y(sf::RenderWindow &win);
    int set_offset_x(sf::RenderWindow &win);
};

#endif //MINESWEEPERBOARD_CPP_MSSFMLVIEW_H
//
// Created by Konrad on 10.04.2022.
//

#ifndef MINESWEEPERBOARD_CPP_MSSFMLCONTROLLER_H
#define MINESWEEPERBOARD_CPP_MSSFMLCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"



class MSSFMLController {
    MinesweeperBoard & board;
    MSSFMLView & view;


public:
    MSSFMLController(MinesweeperBoard & b, MSSFMLView & v);
    void clicking(sf::Event &event, sf::RenderWindow &window);
};


#endif //MINESWEEPERBOARD_CPP_MSSFMLCONTROLLER_H

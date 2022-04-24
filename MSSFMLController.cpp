//
// Created by Konrad on 10.04.2022.
//

#include "MSSFMLController.h"
#include <iostream>
using namespace std;

MSSFMLController::MSSFMLController(MinesweeperBoard &b, MSSFMLView &v) : board(b), view(v)
{

}
void MSSFMLController::clicking(sf::Event &event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed){
int col,row;

if(board.getBoardHeight()<14 or board.getBoardWidth()<14)
{

         col = ((event.mouseButton.y -view.set_offset_y(window))/40);

         row = ((event.mouseButton.x -view.set_offset_x(window))/40);
}

else if(board.getBoardHeight()>=14 or board.getBoardWidth()>=14)
{
    col = ((event.mouseButton.y - view.set_offset_y(window))/view.set_scale(window));

    row = ((event.mouseButton.x - view.set_offset_x(window))/view.set_scale(window));
}
        if(event.mouseButton.button == sf::Mouse::Left){

            board.revealField(row, col);
            return;
        }
        if(event.mouseButton.button == sf::Mouse::Right){

            if(board.getFieldInfo(row, col) == 'F')
            {
                board.toggleFlag(row, col);
            }
            else
            {
                board.toggleFlag(row, col);
            }
        }
    }
}


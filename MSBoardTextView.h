//
// Created by Konrad on 29.03.2022.
//

#ifndef MINESWEEPERBOARD_CPP_MSBOARDTEXTVIEW_H
#define MINESWEEPERBOARD_CPP_MSBOARDTEXTVIEW_H

#include <iostream>
class MinesweeperBoard;
class MSBoardTextView {
    MinesweeperBoard & plansza;

public:
    explicit MSBoardTextView (MinesweeperBoard & board);
    void display();
};


#endif //MINESWEEPERBOARD_CPP_MSBOARDTEXTVIEW_H
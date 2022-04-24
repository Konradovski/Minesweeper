//
// Created by Konrad on 02.04.2022.
//

#ifndef MINESWEEPERBOARD_CPP_MSTEXTCONTROLLER_H
#define MINESWEEPERBOARD_CPP_MSTEXTCONTROLLER_H

#include <iostream>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"


class MinesweeperBoard;
class MSBoardTextView;

class MSTextController {

    MinesweeperBoard & plansza;
    MSBoardTextView & widok;

public:

    void play();

    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
};


#endif //MINESWEEPERBOARD_CPP_MSTEXTCONTROLLER_H

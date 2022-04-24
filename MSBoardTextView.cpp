//
// Created by Konrad on 29.03.2022.
//
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView (MinesweeperBoard & board ) : plansza(board)
{

}

void MSBoardTextView::display()
{
    for(int row=0;row<plansza.getBoardHeight();row++){
        for(int col=0;col<plansza.getBoardWidth(); col++)
        {
            std::cout<<"["<<plansza.getFieldInfo(row,col)<<"]";}
        std::cout<<std::endl;
    }
}

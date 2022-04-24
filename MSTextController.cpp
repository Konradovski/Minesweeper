#include <iostream>
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MinesweeperBoard.h"


//
// Created by Konrad on 02.04.2022.
//
MSTextController::MSTextController(MinesweeperBoard & board, MSBoardTextView & view) : plansza(board), widok(view)
{

}
void MSTextController :: play(){
    widok.display();
    while(plansza.getGameState()==RUNNING)
    {
        char enter;
        int row,col;
        std::cout<<"Podaj numer wiersza: "<<std::endl;
        std::cin>>row;
        row=row-1;
        std::cout<<"Podaj numer kolumny: "<<std::endl;
        std::cin>>col;
        col=col-1;
        if(!plansza.IsValid(row,col))
        {
            std::cout<<"Podano nieprawidlowe polozenie"<<std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout<<"Posiadane opcje: Flaga(f) / Odkrycie Pola(o)"<<std::endl;
        std::cin>>enter;
        if(enter == 'f')
            plansza.toggleFlag(row,col);
        if(enter == 'o')
            plansza.revealField(row,col);
        widok.display();
        if(plansza.getGameState()==FINISHED_WIN)
        {
            std::cout<<"Gratulacje! Wygrana!"<<std::endl;
        }
        if(plansza.getGameState()==FINISHED_LOSS)
        {
            std::cout<<"Trafiles na mine, powodzenia nastepnym razem!"<<std::endl;
        }
    }

}

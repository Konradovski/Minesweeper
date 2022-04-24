//
// Created by Konrad on 21.03.2022.
//
#include "MinesweeperBoard.h"
#include <iostream>
#include <cstdlib>




void intro()
{
    std::cout<<"Konrad Tokarz 41\n";
}
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode){

    this->width=width;
    this->height=height;
    this->firstmove=true;
    clear_board();


    if(mode == DEBUG)
    {
        for(int row=0; row<height; row++)
        {
            for(int col=0; col<width; col++)
            {
                if (row == col || row==0 || (col ==0 && row%2 == 0))
                {
                    board[row][col] = {true, false, false};
                }
            }
        }
    }
    if(mode == EASY)
    {
        int Mines_Easy = ((width * height)*10/100);
        if(Mines_Easy<=0)
            Mines_Easy+=1;
        for (int Bomb = 0; Bomb < Mines_Easy; Bomb++){
            int Randomheight = rand() % height;
            int Randomwidth = rand() % width;
            if (board[Randomheight][Randomwidth].hasMine)
                Bomb -= 1;
            board[Randomheight][Randomwidth].hasMine = true;
        }
    }
    if(mode == NORMAL)
    {
        int Mines_Normal = (width * height)*20/100;
        if(Mines_Normal<=0)
            Mines_Normal+=1;
        for (int Bomb = 0; Bomb < Mines_Normal; Bomb++){
            int Randomheight = rand() % height;
            int Randomwidth = rand() % width;
            if (board[Randomheight][Randomwidth].hasMine)
                Bomb -= 1;
            board[Randomheight][Randomwidth].hasMine = true;
        }
    }
    if(mode == HARD)
    {

        int Mines_Hard = (width * height)*30/100;
        if(Mines_Hard<0)
            Mines_Hard+=1;
        for (int Bomb = 0; Bomb < Mines_Hard; Bomb++){
            int Randomheight = rand() % height;
            int Randomwidth = rand() % width;
            if (board[Randomheight][Randomwidth].hasMine)
                Bomb -= 1;
            board[Randomheight][Randomwidth].hasMine = true;
        }
    }
    state = RUNNING;
}
int MinesweeperBoard::getBoardWidth() const
{
    return width;
}
int MinesweeperBoard::getBoardHeight() const{
    return height;
}
void MinesweeperBoard::clear_board(){
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++){
            board[row][col].hasMine = false;
            board[row][col].hasFlag = false;
            board[row][col].isRevealed = false;
        }
    }
}
int MinesweeperBoard::getMineCount() const {
    int licznik=0;
    for (int row = 0; row < width; row++) {
        for (int col = 0; col < height; col++) {
            if (board[row][col].hasMine)
                licznik++;
        }
    }
    return licznik;
}
bool MinesweeperBoard::isRevealed(int row, int col) const {
    if (board[row][col].isRevealed)
        return true;
    return false;
}
int MinesweeperBoard::countMines(int row, int col) const{
    int counter_near_bombs=0;
    if(!IsValid(row,col))
        return -1;

    if(IsValid(row-1,col) && board[row-1][col].hasMine)
        counter_near_bombs++;
    if(IsValid(row+1,col) && board[row+1][col].hasMine)
        counter_near_bombs++;
    if(IsValid(row,col+1) && board[row][col+1].hasMine)
        counter_near_bombs++;
    if(IsValid(row,col-1) && board[row][col-1].hasMine)
        counter_near_bombs++;
    if(IsValid(row-1,col+1) && board[row-1][col+1].hasMine)
        counter_near_bombs++;
    if(IsValid(row-1,col-1) && board[row-1][col-1].hasMine)
        counter_near_bombs++;
    if(IsValid(row+1,col+1) && board[row+1][col+1].hasMine)
        counter_near_bombs++;
    if(IsValid(row+1,col-1) && board[row+1][col-1].hasMine)
        counter_near_bombs++;
    return counter_near_bombs;
}
bool MinesweeperBoard::IsValid(int row, int col) const{
    if(row >= height or col >= width)
        return false;
    if(col < 0 or row < 0)
        return false;
    return true;
}
void MinesweeperBoard::debug_display() const {
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            std::cout << "[";
            if(board[row][col].hasMine)
                std::cout << "M";
            else
                std::cout << ".";
            if(board[row][col].isRevealed)
                std::cout << "o";
            else
                std::cout << ".";
            if(board[row][col].hasFlag)
                std::cout << "f";
            else
                std::cout << ".";
            std::cout << "]";

        }
        std::cout<<std::endl;
    }
}
void MinesweeperBoard::toggleFlag(int row, int col) {
    if(!IsValid(row,col));
    else if(board[row][col].isRevealed);
    else if(this->state == FINISHED_LOSS or this->state == FINISHED_WIN);
    else if(!board[row][col].isRevealed)
    {
        if(board[row][col].hasFlag)
        {
            board[row][col].hasFlag = false;
            if(this->firstmove)
                this->firstmove = false;
        }
        else board[row][col].hasFlag = true;
    }

}
bool MinesweeperBoard::hasFlag(int row, int col) const {
    if(!IsValid(row,col))
        return false;
    if(board[row][col].hasFlag)
        return true;
    if(!board[row][col].hasFlag)
        return false;
    if(board[row][col].isRevealed)
        return false;
    return false;
}
char MinesweeperBoard::getFieldInfo(int row, int col) const {
    if(!IsValid(row,col))
        return '#';
    if(!isRevealed(row,col) and hasFlag(row,col))
        return 'F';
    if(!isRevealed(row,col) and !hasFlag(row,col))
        return '_';
    if(isRevealed(row,col) and board[row][col].hasMine)
        return 'x';
    if(isRevealed(row,col) and countMines(row,col) == 0)
        return ' ';
    if(isRevealed(row,col) and countMines(row,col) != 0)
        return char (countMines(row, col)+'0');
    return 0;
}
GameState MinesweeperBoard::getGameState() const {
if(state == FINISHED_WIN)
    return FINISHED_WIN;
if(state == FINISHED_LOSS)
    return FINISHED_LOSS;
return RUNNING;
}

void MinesweeperBoard::revealField(int row, int col) {
    int licznik = 1;
    if (!IsValid(row, col))
        return;
    else if (isRevealed(row, col))
        return;
    else if (this->state == FINISHED_WIN or this->state == FINISHED_LOSS)
        return;
    else if (hasFlag(row, col))
        return;
    else {
        if (!isRevealed(row, col) and board[row][col].hasMine) {
            if (this->firstmove) {
                board[row][col].hasMine = false;
                board[row][col].isRevealed = true;
                do {
                    if (!board[rand() % width][rand() % height].hasMine) {
                        board[(rand() % width)][rand() % height].hasMine = true;
                        licznik--;
                    }
                } while (licznik > 0);
                this->firstmove = false;
            }
            else {
                board[row][col].isRevealed = true;
                this->state = FINISHED_LOSS;
            }
        }
        else if (!board[row][col].isRevealed and !board[row][col].hasMine) {
            board[row][col].isRevealed = true;
            if (this->firstmove)
                this->firstmove = false;
        }
    }

    if(Victory())
    {
        this->state=FINISHED_WIN;
    }
    if (countMines(row, col) != 0) return;

    revealField(row-1, col);
    revealField(row, col-1);
    revealField(row+1, col);
    revealField(row, col+1);
    revealField(row-1, col-1);
    revealField(row-1, col+1);
    revealField(row+1, col-1);
    revealField(row+1, col+1);

    if(Victory())
    {
        this->state=FINISHED_WIN;
    }
}

bool MinesweeperBoard::Victory()
{
    int bombs=0;
    for (int row=0;row<height;row++)
    {
        for (int col=0;col<width;col++)
        {
            if (!board[row][col].isRevealed)
                bombs++;
        }
    }
    if(bombs==getMineCount())
    {
        return true;
    }
    return false;
}

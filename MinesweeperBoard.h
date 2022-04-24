//
// Created by Konrad on 21.03.2022.
//

#ifndef MINESWEEPERBOARD_MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};
class MinesweeperBoard
{
    Field board[100][100]{};    // 100-elementowa tablica, 100-elementowych tablic typu Field
    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy
    GameState state;          // status
    void clear_board();
    bool firstmove;


public:

    MinesweeperBoard(int width, int height, GameMode mode);

    bool IsValid(int row, int col) const;

    void debug_display() const;

    int getBoardWidth() const;

    int getBoardHeight() const;

    int getMineCount() const;

    bool isRevealed(int row, int col) const;

    int countMines(int row, int col) const;

    void toggleFlag(int row, int col);

    bool hasFlag(int row, int col) const;

    char getFieldInfo(int row, int col) const;

    void revealField(int row, int col);

    bool Victory();


    GameState getGameState() const;
};


#endif //MINESWEEPERBOARD_MINESWEEPERBOARD_H
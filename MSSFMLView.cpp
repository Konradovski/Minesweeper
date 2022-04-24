//
// Created by Konrad on 07.04.2022.
//


#include <iostream>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <valarray>

using namespace std;

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {
    size_sq=40;
    if (!font.loadFromFile("../Font/arial.ttf"))
    {
        cout<<"Nie można załadować czcionki";
    }
}
void MSSFMLView::Number(sf::RenderWindow & win, char number, int width, int height, int size){
    sf::Text text;
    if(!font.loadFromFile("../Font/arial.ttf"))
        return;
    text.setString(number);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setPosition(width+10,height+10);
    text.setFillColor(sf::Color::Magenta);

    win.draw(text);
}
void MSSFMLView::STATUS(sf::RenderWindow& win)
{
    GameState status = board.getGameState();
    sf::Text text;
    if(!font.loadFromFile("../Font/arial.ttf"))
        return;
    switch (status)
    {
        case FINISHED_WIN:
            text.setString("VICTORY!");
            text.setFillColor(sf::Color::Green);
            text.setPosition(win.getSize().x/2.5,win.getSize().y/50);
            break;

        case FINISHED_LOSS:
            text.setString("LOSE!");
            text.setFillColor(sf::Color::Red);
            text.setPosition(win.getSize().x/2.5,win.getSize().y/50);
            break;
        case RUNNING:
            text.setString("THINK SMART, NOT HARD!");
            text.setFillColor(sf::Color::Yellow);
            text.setPosition(win.getSize().x/4,win.getSize().y/50);
    }
    text.setFont(font);

    text.setCharacterSize(30);
    win.draw(text);
}
void MSSFMLView::set_size_sq(int scr_height, int scr_width) {
    //obliczmy maksymalny rozmiar kwadratu
    float scale;
    float pole = float(board.getBoardHeight()) * float(board.getBoardWidth());

    float SpaceonScreen = scr_height*scr_width;
    scale = SpaceonScreen / pole;
    scale =float(sqrt(double(scale)));
    scale-=15;
   size_sq = int(scale);

}
int MSSFMLView::set_scale(sf::RenderWindow &win) {
    //obliczmy maksymalny rozmiar kwadratu
    float scale;
    float pole = float(board.getBoardHeight()) * float(board.getBoardWidth());

    float SpaceonScreen = win.getSize().x * win.getSize().y;
    scale = SpaceonScreen / pole;
    scale =float(sqrt(double(scale)));
    scale-=15;
    return scale;
}
int MSSFMLView::set_offset_x(sf::RenderWindow &win)
{
    int offset_x=(win.getSize().x-(size_sq *board.getBoardWidth()))/2;
    return offset_x;
}
int MSSFMLView::set_offset_y(sf::RenderWindow &win)
{
    int offset_y=(win.getSize().y-(size_sq *board.getBoardHeight()))/2;
    return offset_y;
}
void MSSFMLView::draw (sf::RenderWindow & win) {

    font.loadFromFile("../Font/arial.ttf");
    scr_height = win.getSize().x;
    scr_width = win.getSize().y;

    int offset_y = (scr_width - (size_sq * board.getBoardWidth())) / 2 ;
    int offset_x =(scr_height - (size_sq * board.getBoardHeight())) / 2 ;

    if (board.getBoardWidth() * (size_sq)>= scr_width or board.getBoardHeight() * (size_sq) >= scr_height)
        set_size_sq(scr_height, scr_width);

    sf::RectangleShape R(sf::Vector2f(size_sq, size_sq));
    R.setOutlineThickness(1);
    R.setOutlineColor(sf::Color::Blue);
    for (int row = 0; row < board.getBoardHeight(); ++row) {
        for (int col = 0; col < board.getBoardWidth(); ++col) {
            char sign = board.getFieldInfo(row, col);
            if (sign == 'F')
                R.setFillColor(sf::Color::Red);
            else if (sign == '_')
                R.setFillColor(sf::Color::White);
            else if (sign == 'x')
                R.setFillColor(sf::Color::Blue);
            else if (board.getFieldInfo(row, col) >= '0' and board.getFieldInfo(row, col) <= '9')
                R.setFillColor(sf::Color(120, 230, 100));
            else
                R.setFillColor(sf::Color::Green);

            R.setPosition(offset_x+(size_sq)*row+(board.getBoardHeight()-board.getBoardWidth())*20, offset_y+(size_sq)*col-(board.getBoardHeight()-board.getBoardWidth())*20);
            win.draw(R);

            if (board.getFieldInfo(row, col) >= '0' and board.getFieldInfo(row, col) <= '9')
                Number(win, sign, offset_x+(size_sq)*row-3+(board.getBoardHeight()-board.getBoardWidth())*20,offset_y+(size_sq)*col-14-(board.getBoardHeight()-board.getBoardWidth())*20,size_sq);
        }
        STATUS(win);
    }
    sf::Text Autor("Autor: \nKonrad Tokarz", font, 15);
    Autor.setPosition(15,25);
    Autor.setFillColor(sf::Color::Cyan);
    win.draw(Autor);

    sf::Text Legenda("Legenda:\nNiebieski-Bomba\nCzerwien-Flaga\nZielony-puste pole\n\nLMB-odkryj\nRMB-flaga", font, 15);
    Legenda.setPosition(15,100);
    Legenda.setFillColor(sf::Color::Yellow);
    win.draw(Legenda);
}
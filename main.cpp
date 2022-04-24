//
// Created by Konrad on 02.04.2022.
//
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <ctime>
#include "MSSFMLController.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

using namespace std;
int main()
{
    srand(time(nullptr));

    constexpr int screen_width = 800;
    constexpr int screen_height = 600;

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "MinesweeperBoard");
      window.setVerticalSyncEnabled(false);
      window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, EASY);
    MSSFMLView view(board);  // przekazujemy przez referencje plansze jako argument konstruktora
    MSSFMLController akcja(board, view);

    //board.debug_display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    switch (event.key.code)
                    {
                        case sf::Mouse::Left:
                            akcja.clicking(event,window);
                            break;
                        case sf::Mouse::Right:
                            akcja.clicking(event,window);
                            break;
                    }
                    break;
            }
        }
       window.clear(sf::Color(50, 50, 50));
        view.draw(window);
        window.display();
    }
}

//void test()
//{
//        while (true)
//        {
//            char ctrl1;
//            std::cout << "Nowa gra? (y/n)";
//            std::cin >> ctrl1;
//            if (ctrl1=='y' or ctrl1=='Y')
//            {
//                MinesweeperBoard b={5,5,EASY};
//                b.debug_display();
//                MSBoardTextView view (b);
//                std::cout << std::endl;
//                MSTextController ctrl (b,view);
//
//                ctrl.play();
//
//            }
//            else if (ctrl1 == 'n' or ctrl1 == 'N') break;
//            else continue;
//        }
//    }
//
//
//    int main() {
//        srand(time(nullptr));
//
//
//        test();
//}





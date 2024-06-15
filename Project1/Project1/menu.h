#ifndef GAME_MENU_H
#define GAME_MENU_H

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * \menu.h
 *
 * This file contains a function that creates a menu.
 */

/**
 * This function brings up a menu where you can choose which 
 * map to play on && the option to exit the game.
 *
 * \param[in] window is input window in the format of a RenderWindow.
 *
 * \return Number of the card we will play on.
 */
int menu(sf::RenderWindow& window) {
    sf::Texture menuTexture1, menuTexture2, menuTexture3, map1Texture,
                map2Texture, map3Texture, menuBackground;
    menuTexture1.loadFromFile("texture/menu/play.png");
    menuTexture2.loadFromFile("texture/menu/select.png");
    menuTexture3.loadFromFile("texture/menu/exit.png");
    map1Texture.loadFromFile("texture/menu/map_1.png");
    map2Texture.loadFromFile("texture/menu/map_2.png");
    map3Texture.loadFromFile("texture/menu/map_3.png");
    menuBackground.loadFromFile("texture/menu/texture_menu.jpg");

    sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),
               map1(map1Texture), map2(map2Texture), map3(map3Texture),
               menuBg(menuBackground);
    bool isMenu = true;
    bool isMenu2 = false;
    int menuNum = 0;
    int mapNum = 0;
    int numberMap = 0;
    menu1.setPosition(325, 195);
    menu2.setPosition(242, 265);
    menu3.setPosition(330, 335);
    menuBg.setPosition(0, 0);

    map1.setPosition(345, 195);
    map2.setPosition(345, 265);
    map3.setPosition(345, 335);

    while (isMenu) {
        menu1.setColor(sf::Color::White);
        menu2.setColor(sf::Color::White);
        menu3.setColor(sf::Color::White);

        if (sf::IntRect(325, 195, 125, 60).
            contains(sf::Mouse::getPosition(window))) {
            menu1.setColor(sf::Color::Blue);
            menuNum = 1;
        }
        if (sf::IntRect(242, 265, 300, 60).
            contains(sf::Mouse::getPosition(window))) {
            menu2.setColor(sf::Color::Blue);
            menuNum = 2;
        }
        if (sf::IntRect(330, 335, 125, 60).
            contains(sf::Mouse::getPosition(window))) {
            menu3.setColor(sf::Color::Blue);
            menuNum = 3;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (menuNum == 1) {
                numberMap = 1;
                return numberMap;
            } // если нажали первую кнопку, то выходим из меню
            if (menuNum == 2) {
                isMenu2 = true;
                while (isMenu2) {
                    map1.setColor(sf::Color::White);
                    map2.setColor(sf::Color::White);
                    map3.setColor(sf::Color::White);
                    mapNum = 0;

                    if (sf::IntRect(330, 195, 125, 60).
                        contains(sf::Mouse::getPosition(window))) {
                        map1.setColor(sf::Color::Blue);
                        mapNum = 1;
                    }
                    if (sf::IntRect(330, 265, 125, 60).
                        contains(sf::Mouse::getPosition(window))) {
                        map2.setColor(sf::Color::Blue);
                        mapNum = 2;
                    }
                    if (sf::IntRect(330, 335, 125, 60).
                        contains(sf::Mouse::getPosition(window))) {
                        map3.setColor(sf::Color::Blue);
                        mapNum = 3;
                    }

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                        if (mapNum == 1) {
                            isMenu = false;
                            isMenu2 = false;
                            numberMap = 1;
                        }
                        if (mapNum == 2) {
                            isMenu = false;
                            isMenu2 = false;
                            numberMap = 2;
                        }
                        if (mapNum == 3) {
                            isMenu = false;
                            isMenu2 = false;
                            numberMap = 3;
                        }
                    }
                    window.clear();
                    window.draw(menuBg);
                    window.draw(map1);
                    window.draw(map2);
                    window.draw(map3);
                    window.display();
                }
                return numberMap;
            }
            if (menuNum == 3) {
                numberMap = 4;
                isMenu = false;
                window.close();
                return numberMap;
            }
        }
        window.clear();
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.display();
    }
    window.clear();
}

#endif GAME_MENU_H
/*
* Dimitri Nanmejo
* 2170-002
* Filename: Board.cpp
* Instructor: Robert Smith
* Course: CSCI 2170
* Due Date: 11/016/2024
* input: User input
* Output: minesweeper game
* Description: Make the game playable! Update your Board and Tile class with the necessary private and
public members such that the game can be played in a similar fashion to the sample runs. It's
up to you to determine how and what to implement.
AI DISCLAIMER: All work for this assignment was completed by myself and entirely without the use of artificial intelligence tools such as ChatGPT, MS Copilot, other LLMs, etc.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DoubleLinked.h"

int main() {
    DoubleLinked game_check;
    std::ifstream inputFile;
    std::string filename;

    std::cout << "Enter a game to review: ";
    std::cin >> filename;

    inputFile.open(filename);
    if (!inputFile) {
        std::cout << "ERROR: " << filename << " could not be opened...\n";
        return 1;
    }

    std::string value_white, value_black;
    inputFile >> value_white >> value_black;
    while (inputFile) {
        game_check.push_back(value_white, value_black);
        inputFile >> value_white >> value_black;
    }

    char command;
    std::cout << "---Game Start---\n";
    game_check.display_current_move();

    do {
        std::cout << "Enter n/p/q: ";
        std::cin >> command;
        switch (command) {
            case 'n':
                game_check.forward();
                break;
            case 'p':
                game_check.back_move();
                break;
            case 'q':
                std::cout << "--- Ending Review ---\n";
                break;
        }
        if (command != 'q') {
            game_check.display_current_move();
        }
    } while (command != 'q');

    return 0;
}

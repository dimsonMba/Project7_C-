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

#ifndef DOUBLELINKED_H
#define DOUBLELINKED_H

#include <string>

struct Node {
    std::string white_move;
    std::string black_move;
    Node* previous;
    Node* next;
};

class DoubleLinked {
private:
    Node* head;
    Node* tail;
    Node* current; // Pointer to track current move

public:
    DoubleLinked();
    void push_back(const std::string& white_move, const std::string& black_move);
    void forward();
    void back_move();
    void display_current_move() const;
    ~DoubleLinked();
};

#endif

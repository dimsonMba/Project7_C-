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
#include <string>
#include "DoubleLinked.h"

// Constructor
DoubleLinked::DoubleLinked(){
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

// Add a new move to the linked list
void DoubleLinked::push_back(const std::string& white_move, const std::string& black_move) {
    Node* new_node = new Node{white_move, black_move, nullptr, nullptr};
    if (!head) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->previous = tail;
        tail = new_node;
    }
    if (!current) current = head;
}

// Move forward in the list
void DoubleLinked::forward() {
    if (current && current->next) {
        current = current->next;
    } else {
        std::cout << "No next move...\n";
    }
}

// Move backward in the list
void DoubleLinked::back_move() {
    if (current && current->previous) {
        current = current->previous;
    } else {
        std::cout << "No previous move...\n";
    }
}

// Display the current move
void DoubleLinked::display_current_move() const {
    if (current) {
        if (current->previous) {
            std::cout << "Turn " << (current->previous->white_move.empty() ? 1 : 2)
                      << ": White - " << current->white_move
                      << "\nTurn " << (current->previous->white_move.empty() ? 1 : 2)
                      << ": Black - " << current->black_move << "\n";
        } else {
            std::cout << "White";
        }
    } else {
        std::cout << "---Game Start---\n";
    }
}

// Destructor
DoubleLinked::~DoubleLinked() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <vector>

template <typename T>
class GameDecisionTree {
private:
    Node<T> *root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {

        string line;
        ifstream file("../Pham_JasonRPG/" + filename);
        vector< Node<T>* > vectorOfNodes;
        Node<T> *node;

        string eventNumber, eventDescription, leftNum, rightNum;

        while ( getline(file, line) ) {
            stringstream lineStreamed(line);
            getline(lineStreamed, eventNumber, '|');
            getline(lineStreamed, eventDescription, '|');
            getline(lineStreamed, leftNum, '|');
            getline(lineStreamed, rightNum, '|');
            Story storyline(eventDescription, stoi(eventNumber), stoi(leftNum), stoi(rightNum) );
            node = new Node<T>(storyline);
            vectorOfNodes.push_back( node );
        }

        root = vectorOfNodes[0];
        for (Node<T> *temp: vectorOfNodes) {
            if (temp -> data.leftEventNumber == -1 && temp -> data.rightEventNumber == -1) {
                temp -> left = NULL;
                temp -> right = NULL;
            }
            else if (temp -> data.leftEventNumber == -1 && temp -> data.rightEventNumber != -1) {
                temp -> left = NULL;
                temp -> right = vectorOfNodes.at(temp -> data.rightEventNumber - 1);
            }
            else if (temp -> data.leftEventNumber != -1 && temp -> data.rightEventNumber == -1) {
                temp -> left = vectorOfNodes.at(temp -> data.leftEventNumber - 1);
                temp -> right = NULL;
            }
            else {
                temp -> left = vectorOfNodes.at(temp -> data.leftEventNumber - 1);
                temp -> right = vectorOfNodes.at(temp -> data.rightEventNumber - 1);
            }
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T> *temp = root;

        while (temp) {
            cout << temp -> data.description;
            if (temp -> left == NULL && temp -> right == NULL) {
                cout << "\nYou've reached the end. Thanks for playing!";
                temp = NULL;
            }
            else if (temp -> left != NULL && temp -> right == NULL) {
                cout << " Enter 1 to continue.";
                validateUserInput("Single Option");
                temp = temp -> left;
            }
            else if (temp -> left == NULL && temp -> right != NULL) {
                cout << " Enter 1 to continue.";
                validateUserInput("Single Option");
                temp = temp -> right;
            }
            else {
                cout << " 1 or 2? - ";
                int userInput = validateUserInput("Double Option");
                if (userInput == 1)
                    temp = temp -> left;
                else if (userInput == 2)
                    temp = temp -> right;
            }
        }
    }

    int validateUserInput(string typeOfLeaf) {
        string userInput;
        if (typeOfLeaf == "Single Option") {
            cin >> userInput;
            while (userInput != "1") {
                cout << "Please press enter 1 to continue. -";
                cin >> userInput;
            }
            return 1;
        }

        if (typeOfLeaf == "Double Option") {
            cin >> userInput;
            while (userInput != "1" && userInput != "2") {
                cout << "Please enter either 1 or 2 to choose your path. -";
                cin >> userInput;
            }
            return stoi(userInput);
        }
        return 1; //placeholder line to avoid errors, this will never actually run.
    }

};

#endif // GAMEDECISIONTREE_H

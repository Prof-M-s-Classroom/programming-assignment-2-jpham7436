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
        ifstream file(filename);
        vector< Node<T>* > vectorOfNodes;

        string eventNumber, eventDescription, leftNum, rightNum;

        while ( getline(file, line) ) {
            stringstream lineStreamed(line);
            getline(lineStreamed, eventNumber, '|');
            getline(lineStreamed, eventDescription, '|');
            getline(lineStreamed, leftNum, '|');
            getline(lineStreamed, rightNum, '|');
            Story storyline(stoi(eventNumber), eventDescription, stoi(leftNum), stoi(rightNum));
            Node<T> *node = new Node(storyline);
            vectorOfNodes.push_back( node );
        }

        root = vectorOfNodes.at(0);
        for (Node<T> *node: vectorOfNodes) {
            if (node -> data.leftEventNumber == -1 && node -> data.leftEventNumber == -1) {
                node -> left = NULL;
                node -> right = NULL;
            }
            else if (node -> data.leftEventNumber == -1 && node -> data.rightEventNumber != -1) {
                node -> left = NULL;
                node -> right = vectorOfNodes.at(node -> data.rightEventNumber - 1);
            }
            else if (node -> data.leftEventNumber != -1 && node -> data.rightEventNumber == -1) {
                node -> left = vectorOfNodes.at(node -> data.leftEventNumber - 1);
                node -> right = NULL;
            }
            else {
                node -> left = vectorOfNodes.at(node -> data.leftEventNumber - 1);
                node -> right = vectorOfNodes.at(node -> data.rightEventNumber - 1);
            }
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T> *temp = root;
        int userIntInput;
        string userStringInput;
        while (temp) {
            cout << "\n" << temp -> data.description;
            if (temp -> left == NULL && temp -> right == NULL) {
                cout << "\nYou've reached the end. Thanks for playing!";
                temp = NULL;
            }
            else if (temp -> left != NULL && temp -> right == NULL) {
                cout << " " << temp -> data.leftEventNumber << " Continue?";
                cin >> userStringInput;
                temp = temp -> left;
            }
            else if (temp -> left == NULL && temp -> right != NULL) {
                cout << " " << temp -> data.rightEventNumber << " Continue?";
                cin >> userStringInput;
                temp = temp -> right;
            }
            else {
                cout << temp -> data.leftEventNumber << " or " << temp -> data.rightEventNumber << "?";
                cin >> userIntInput;
                if (userIntInput == temp -> data.leftEventNumber)
                    temp = temp -> left;
                else if (userIntInput == temp -> data.rightEventNumber)
                    temp = temp -> right;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H

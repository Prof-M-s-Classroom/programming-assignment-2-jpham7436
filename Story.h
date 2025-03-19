#ifndef STORY_H
#define STORY_H

#include <string>
using namespace std;
class Story {
public:
    int eventNumber;
    string description;
    int leftEventNumber;
    int rightEventNumber;

    // Default constructor
    Story();

    // Parameterized constructor
    Story(int num, string desc, int leftNum, int rightNum);
};

#endif // STORY_H

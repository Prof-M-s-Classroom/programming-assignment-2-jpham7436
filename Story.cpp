#include "Story.h"

Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

Story::Story(int num, std::string desc, int leftNum, int rightNum)
        : eventNumber(num), description(desc), leftEventNumber(leftNum), rightEventNumber(rightNum) {}

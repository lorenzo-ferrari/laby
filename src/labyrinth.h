#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "constants.h"

#ifndef LABYRINTH_TYPE_DEFINED
#define LABYRINTH_TYPE_DEFINED
struct Labyrinth_type {
    std::vector<std::vector<char>> plan;
    std::vector<std::vector<bool>> reachable;

    Labyrinth_type(int rows, int columns) {
        plan.assign(rows, std::vector<char> (columns, WALL));
        reachable.assign(rows, std::vector<bool> (columns, false));
    }
};
#endif

void generate(int x, int y, Labyrinth_type &labyrinth);
void printLabyrinth(Labyrinth_type &labyrinth);
void initLabyrinth(Labyrinth_type &labyrinth);
bool checkForErrors();

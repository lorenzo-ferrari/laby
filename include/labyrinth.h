#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "constants.h"

struct Laby_t {
    std::vector<std::vector<char>> plan;
    std::vector<std::vector<bool>> reachable;

    Laby_t(int, int);
};

void generate(int x, int y, Laby_t &labyrinth);
void printLabyrinth(Laby_t &labyrinth);
void initLabyrinth(Laby_t &labyrinth);
bool checkForErrors();
#endif
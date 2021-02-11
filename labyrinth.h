#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "constants.h"
#include "aliases.h"

void generate(int x, int y, std::vector<std::vector<char>> &labyrinth, std::vector<std::vector<bool>> &vis);
void printLabyrinth(std::vector<std::vector<char>> &labyrinth);
bool checkForErrors();
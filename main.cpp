#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "labyrinth.h"
#include "constants.h"
#include "aliases.h"

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main() {
    if(checkForErrors()) {
        return 0;
    }
    
    std::srand(std::time(NULL));

    std::vector<std::vector<char>> labyrinth(ROWS, std::vector<char> (COLUMNS, WALL));

    for (int i = 1; i < ROWS; i += 2) {
        for (int j = 1; j < COLUMNS; j += 2) {
            labyrinth[i][j] = EMPTY;
        }
    }

    std::vector<std::vector<bool>> vis(ROWS, std::vector<bool> (COLUMNS, false));

    generate(1, 1, labyrinth, vis);

    printLabyrinth(labyrinth);

    return 0;
}
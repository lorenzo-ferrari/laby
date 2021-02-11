#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "labyrinth.h"
#include "constants.h"

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main() {
    // freopen(INPUT_FILE, "r", stdin);
    // freopen(OUTPUT_FILE, "w", stdout);

    if(checkForErrors()) {
        return 0;
    }
    
    std::srand(std::time(NULL));

    Labyrinth_type labyrinth(ROWS, COLUMNS);
    initLabyrinth(labyrinth);

    generate(1, 1, labyrinth);

    printLabyrinth(labyrinth);

    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include "labyrinth.h"
#include "constants.h"
#include "aliases.h"


#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3


#ifndef GENERATE
#define GENERATE
void generate(int x, int y, Labyrinth_type &labyrinth) {
    std::vector<int> randomDirections {UP, LEFT, DOWN, RIGHT};
    random_shuffle(randomDirections.begin(), randomDirections.end());

    for (int direction: randomDirections) {
        switch (direction) {
            case UP:
                if (x - 2 > 0 && !labyrinth.reachable[x - 2][y]) {
                    labyrinth.plan[x - 1][y] = EMPTY;
                    labyrinth.reachable[x - 2][y] = true;
                    generate(x - 2, y, labyrinth);
                }
                break;

            case LEFT:
                if (y - 2 > 0 && !labyrinth.reachable[x][y - 2]) {
                    labyrinth.plan[x][y - 1] = EMPTY;
                    labyrinth.reachable[x][y - 2] = true;
                    generate(x, y - 2, labyrinth);
                }
                break;

            case DOWN:
                if (x + 2 < ROWS && !labyrinth.reachable[x + 2][y]) {
                    labyrinth.plan[x + 1][y] = EMPTY;
                    labyrinth.reachable[x + 2][y] = true;
                    generate(x + 2, y, labyrinth);
                }
                break;
            
            case RIGHT:
                if (y + 2 < COLUMNS && !labyrinth.reachable[x][y + 2]) {
                    labyrinth.plan[x][y + 1] = EMPTY;
                    labyrinth.reachable[x][y + 2] = true;
                    generate(x, y + 2, labyrinth);
                }
                break;

        }
    }
}
#endif


#ifndef PRINT_LABYRINTH
#define PRINT_LABYRINTH
void printLabyrinth(Labyrinth_type &labyrinth) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << labyrinth.plan[i][j];
        }
        std::cout << std::endl;
    }
}
#endif


bool checkForErrors() {
    if (ROWS < 3 || COLUMNS < 3 || ROWS % 2 == 0 || COLUMNS % 2 == 0) {
        std::cout << "ERROR: ";
        std::cout << "'ROWS' and 'COLUMNS' must be odd numbers greater or equal 3" << std::endl;

        return true;
    }

    return false;
}


#ifndef INIT_LABYRINTH
#define INIT_LABYRINTH
void initLabyrinth(Labyrinth_type &labyrinth) {
    labyrinth.reachable[1][1] = true;

    for (int i = 1; i < ROWS; i += 2) {
        for (int j = 1; j < COLUMNS; j += 2) {
            labyrinth.plan[i][j] = EMPTY;
        }
    }
}
#endif
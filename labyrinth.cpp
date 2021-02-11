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

#ifndef DIRECTIONS
#define DIRECTIONS
std::vector<int> directions {UP, LEFT, DOWN, RIGHT};
#endif

#ifndef GENERATE
#define GENERATE
void generate(int x, int y, std::vector<std::vector<char>> &labyrinth, std::vector<std::vector<bool>> &vis) {
    random_shuffle(directions.begin(), directions.end());

    for (int direction: directions) {
        switch (direction) {
            case UP:
                if (x - 2 > 0 && !vis[x - 2][y]) {
                    labyrinth[x - 1][y] = EMPTY;
                    vis[x - 2][y] = true;
                    generate(x - 2, y, labyrinth, vis);
                }
                break;

            case LEFT:
                if (y - 2 > 0 && !vis[x][y - 2]) {
                    labyrinth[x][y - 1] = EMPTY;
                    vis[x][y - 2] = true;
                    generate(x, y - 2, labyrinth, vis);
                }
                break;

            case DOWN:
                if (x + 2 < ROWS && !vis[x + 2][y]) {
                    labyrinth[x + 1][y] = EMPTY;
                    vis[x + 2][y] = true;
                    generate(x + 2, y, labyrinth, vis);
                }
                break;
            
            case RIGHT:
                if (y + 2 < COLUMNS && !vis[x][y + 2]) {
                    labyrinth[x][y + 1] = EMPTY;
                    vis[x][y + 2] = true;
                    generate(x, y + 2, labyrinth, vis);
                }
                break;

        }
    }
}
#endif

#ifndef PRINT_LABYRINTH
#define PRINT_LABYRINTH
void printLabyrinth(std::vector<std::vector<char>> &labyrinth) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << labyrinth[i][j];
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
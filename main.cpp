#include <bits/stdc++.h>

using namespace std;

// ROWS and COLUMNS muste be odd to work properly
#define ROWS 15
#define COLUMNS 41

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#define EMPTY ' '
#define WALL '#'

int dir[] {0, 1, 2, 3};

void dfs(int x, int y, vector<vector<char>> &lab, vector<vector<bool>> &vis) {
    random_shuffle(dir, dir + 4);

    for (int i = 0; i < 4; i++) {
        switch (dir[i]) {
            case UP:
                if (x - 2 > 0 && !vis[x - 2][y]) {
                    lab[x - 1][y] = EMPTY;
                    vis[x - 2][y] = true;
                    dfs(x - 2, y, lab, vis);
                }
                break;

            case LEFT:
                if (y - 2 > 0 && !vis[x][y - 2]) {
                    lab[x][y - 1] = EMPTY;
                    vis[x][y - 2] = true;
                    dfs(x, y - 2, lab, vis);
                }
                break;

            case DOWN:
                if (x + 2 < ROWS && !vis[x + 2][y]) {
                    lab[x + 1][y] = EMPTY;
                    vis[x + 2][y] = true;
                    dfs(x + 2, y, lab, vis);
                }
                break;
            
            case RIGHT:
                if (y + 2 < COLUMNS && !vis[x][y + 2]) {
                    lab[x][y + 1] = EMPTY;
                    vis[x][y + 2] = true;
                    dfs(x, y + 2, lab, vis);
                }
                break;

        }
    }
}

void print(std::vector<std::vector<char>> &lab) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cerr << lab[i][j];
        }
        std::cerr << "\n";
    }
}

int main() {
    if (ROWS < 3 || COLUMNS < 3 || ROWS % 2 == 0 || COLUMNS % 2 == 0) {
        std::cout << "ERROR: ";
        std::cout << "'ROWS' and 'COLUMNS' must be odd numbers greater or equal 3" << std::endl;

        return 0;
    }

    srand(time(NULL));

    vector<vector<char>> lab(ROWS, vector<char> (COLUMNS, WALL));

    for (int i = 1; i < ROWS; i += 2) {
        for (int j = 1; j < COLUMNS; j += 2) {
            lab[i][j] = EMPTY;
        }
    }

    vector<vector<bool>> vis(ROWS, vector<bool> (COLUMNS, false));

    dfs(1, 1, lab, vis);

    print(lab);

    return 0;
}
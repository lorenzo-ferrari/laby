#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

#include "labyrinth.h"


laby_t::laby_t (int _rows, int _cols) : rows(_rows), cols(_cols) {
    this->map.assign(2 * rows + 1, std::vector<bool> (2 * cols + 1, laby::WALL));
    this->vis.assign(2 * rows + 1, std::vector<bool> (2 * cols + 1, false));

    dfs(1, 1);
}

bool laby_t::valid(int x, int y) {
    if (x < 0 || x >= 2 * this->rows + 1) return false;
    if (y < 0 || y >= 2 * this->cols + 1) return false;
    return true;
}

void laby_t::dfs(int x, int y) {
    this->vis[x][y] = true;
    this->map[x][y] = laby::EMPTY;

    auto local_dirs = laby::dirs;
    random_shuffle(local_dirs.begin(), local_dirs.end());
    for (auto [dx, dy] : local_dirs) {
        int newx = x + dx;
        int newy = y + dy;
        if (valid(newx, newy) && !this->vis[newx][newy]) {
            this->map[x + dx / 2][y + dy / 2] = laby::EMPTY;
            dfs(newx, newy);
        }
    }
}

void laby_t::print(std::ostream& out) {
    for (int i = 0; i < 2* this->rows + 1; ++i) {
        for (int j = 0; j < 2 * this->cols + 1; ++j) {
            if ((i & 1) == 0)
                out << (j & 1 ? (this->map[i][j] ? "---" : "   ") : "+");
            else
                out << (j & 1 ? "   " : (this->map[i][j] ? "|" : " "));
        }
        out << "\n";
    }
}

void laby_t::print_bmp(std::ostream& out) {
    out << "P1" << "\n";
    out << 2 * this->cols + 1 << " " << 2 * this->rows + 1 << "\n";
    for (int i = 0; i < 2* this->rows + 1; ++i) {
        for (int j = 0; j < 2 * this->cols + 1; ++j)
            out << this->map[i][j];
        out << "\n";
    }
}

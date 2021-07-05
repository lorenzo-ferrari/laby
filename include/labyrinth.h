#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

namespace laby
{
#ifdef CLI_ARGUMENTS
    constexpr char WELCOME_FILE[30] { "msg/welcome.txt" };
    constexpr char HELP_FILE[30] { "msg/help.txt" };
    constexpr char UNKNOWN_OPTION[30] { "msg/unknown.txt" };
#endif

    constexpr bool EMPTY { 0 };
    constexpr bool WALL  { 1 };
    
    constexpr std::pair<int, int> UP    { -2,  0 };
    constexpr std::pair<int, int> DOWN  {  2,  0 };
    constexpr std::pair<int, int> LEFT  {  0,  2 };
    constexpr std::pair<int, int> RIGHT {  0, -2 };
    
    constexpr std::array<std::pair<int, int>, 4> dirs { UP, DOWN, LEFT, RIGHT };
}

class laby_t {
public:
    const int rows;
    const int cols;
    std::vector<std::vector<bool>> map;
    std::vector<std::vector<bool>> vis;
    std::vector<std::pair<int, int>> dirs;

    laby_t(int, int);
    bool valid(int, int);
    void dfs(int, int);
    void print(std::ostream&);
    void print_bmp(std::ostream&);
};
#endif

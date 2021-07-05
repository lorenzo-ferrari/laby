#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "labyrinth.h"


int main(int argc, char** argv)
{
    int rows;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    if (std::cin.fail()) {
        std::cout << "Input not valid" << std::endl;;
        exit(EXIT_FAILURE);
    }

    int columns;
    std::cout << "Enter number of columns: ";
    std::cin >> columns;
    if (std::cin.fail()) {
        std::cout << "Input not valid" << std::endl;
        exit(EXIT_FAILURE);
    }

    laby_t labyrinth(rows, columns);
    labyrinth.print(std::cout);

    std::ofstream bmp("output.pbm");
    labyrinth.print_bmp(bmp);

    bmp.close();
}

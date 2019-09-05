#include "Node.hpp"

void        Node::displayGrid(int **grid) const {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            std::cout << std::setw(3);
            if (grid[i][j] != 0)
                std::cout << grid[i][j];
            else
                std::cout << "\033[1;31m  0\033[0m";
        }
        std::cout << std::endl;
    }
}
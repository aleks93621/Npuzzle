#include "Node.hpp"
#include <fstream>

int         **Node::createFirstGrid(std::vector<int> numbers) {

    int     **grid = new int*[_size];
	for (int i = 0; i < _size; i++) {
		grid[i] = new int[_size];
	}


    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            grid[i][j] = numbers.at(i * _size + j);
        }
    }

    return grid;
}
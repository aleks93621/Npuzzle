#include "Node.hpp"

void    Node::createHash() {
    std::string gridString;
    int tmp;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            tmp = getGrid()[i][j];
            gridString += (tmp < 10 ? "0" : "") + std::to_string(tmp);
        }
    }
    _hash = gridString;
}

std::string    Node::createFinalHash() {
    std::string gridString;
    int tmp;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            tmp = getFinalGrid()[i][j];
            gridString += (tmp < 10 ? "0" : "") + std::to_string(tmp);
        }
    }
    return gridString;
}

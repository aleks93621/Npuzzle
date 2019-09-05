#include "Node.hpp"

void Node::misplacedTiles() {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (getGrid()[i][j] != getFinalGrid()[i][j] && getGrid()[i][j] != 0)
                _h++;
        }
    }
}

void Node::manhattanDistance() {
    int a; int b;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (getGrid()[i][j] != getFinalGrid()[i][j] && getGrid()[i][j] != 0) {
                findPos(a, b, getGrid()[i][j]);
                _h += abs((a - i) + (b - j));
            }
        }
    }
}

void Node::linearConflict() {
    int conflicts = 0;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (getGrid()[i][j] != getFinalGrid()[i][j]
            && getGrid()[i][j] != 0 && findConflicts(i, j, conflicts)) {
            }
        }
    }
    this->manhattanDistance();
    _h += 2 * conflicts;
}

void        Node::calculateH() {

    char heuristic = this->getHeuristic();

    _h = 0;
    if (heuristic == 'T')
        this->misplacedTiles();
    else if (heuristic == 'M')
        this->manhattanDistance();
    else if (heuristic == 'L')
        this->linearConflict();
}
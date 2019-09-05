#include "Node.hpp"

void Node::findZero(int &a, int &b, std::string &move) {
    move = "HDBG";
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (this->_grid[i][j] == 0){
                a = i;
                b = j;
                if (i == 0)
                    replace(move.begin(), move.end(), 'H' , '.');
                if (j == 0)
                    replace(move.begin(), move.end(), 'G' , '.');
                if (i == this->_size - 1)
                    replace(move.begin(), move.end(), 'B' , '.');
                if (j == this->_size - 1)
                    replace(move.begin(), move.end(), 'D' , '.');
                return ;
            }
        }
    }
}

void Node::findPos(int &a, int &b, int num) {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (this->getFinalGrid()[i][j] == num) {
                a = i;
                b = j;
                return;
            }
        }
    }
}

bool Node::findConflicts(int a, int b, int &conflicts) {
    int zero = 0;
    for (int i = 0; i < _size; i++) {
        if (getFinalGrid()[i][b] == 0)
            zero++;
        if (getGrid()[a][b] == getFinalGrid()[i][b]) {
            if (i < a)
                conflicts = a - i - zero;
            else
                conflicts = i - zero - a;
            return true;
        }
    }
    zero = 0;
    for (int j = 0; j < _size; j++) {
        if (getFinalGrid()[a][j] == 0)
            zero++;
        if (getGrid()[a][b] == getFinalGrid()[a][j]) {
            if (j < b)
                conflicts = b - j - zero;
            else
                conflicts = j - zero - b;
            return true;
        }
    }
    return false;
}
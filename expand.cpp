#include "Node.hpp"

void    Node::expand(std::priority_queue<Node*, std::vector<Node*>, Comparator>& opened, std::set<std::string>& closed, std::list<Node*>& used) {

    opened.pop();
    closed.insert(this->getHash());

    int i = 0; int j = 0;
    std::string move;
    Node *tmp;

    findZero(i , j, move);
    for (size_t a = 0; a < move.size(); a++) {
        if (move.at(a) != '.') {
            tmp = new Node(_size, _grid, _g, move[a], this, i, j);
            if (closed.count(tmp->getHash()) == 0)
                opened.push(tmp);
            else
                delete tmp;
        }
    }
    if (this->_g > 0)
        used.push_back(this);
}

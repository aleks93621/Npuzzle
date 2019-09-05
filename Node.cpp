#include "Node.hpp"

Node::Node() {
}

Node::Node(int size, std::vector<int> numbers, char heuristic, int option) : _size(size), _parent(NULL), _g(0), _h(1) {

    _finalGrid = createFinalGrid();
    _grid = createFirstGrid(numbers);
    _heuristic = heuristic;
    _option = option;

     this->createHash();
     this->calculateH();
}

Node::Node(int size, int **grid, int g, char move, Node *parent, int a, int b) : _size(size), _parent(parent), _g(g + 1) {
    this->_grid = new int*[size];

    for (int i = 0; i < _size; i++) {
        this->_grid[i] = new int[_size];
    }

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            this->_grid[i][j] = grid[i][j];
        }
    }

    this->_grid[a][b] = grid[a + (move == 'H' ? -1 : (move == 'B' ? 1 : 0))]
        [b + (move == 'G' ? -1 : (move == 'D' ? 1 : 0))];
    this->_grid[a + (move == 'H' ? -1 : (move == 'B' ? 1 : 0))]
        [b + (move == 'G' ? -1 : (move == 'D' ? 1 : 0))] = 0;

     this->createHash();
     this->calculateH();
}

Node::~Node() {
    for (int i = 0; i < _size; i++) {
		delete [] _grid[i];
	}
    delete [] _grid;

    if (_g == 0) {
        for (int i = 0; i < _size; i++) {
		    delete [] _finalGrid[i];
	    }
        delete [] _finalGrid;
    }
}

int **Node::getFinalGrid() const {
    return _finalGrid;
}

int **Node::getGrid() const {
    return _grid;
}

int Node::getF() const {
    if (_option == 0)
        return this->_g + this->_h;
    else if (_option == 1)
        return this->_g;
    else if (_option == 2)
        return this->_h;
    return this->_g + this->_h;
}

int Node::getG() const {
    return this->_g;
}

int Node::getH() const {
    return this->_h;
}

char    Node::getHeuristic() const {
    return _heuristic;    
}

std::string    Node::getHash() const {
    return _hash;    
}

Node*    Node::getParent() const {
    return _parent;    
}

bool operator<(const Node& a, const Node& b) {
    return a.getF() < b.getF();
}

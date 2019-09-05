#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <queue>
#include <set>
#include <list>
#include <stdlib.h>

class Comparator;

class Node {

    public:

        Node();
        Node(int size, std::vector<int> numbers, char heuristic, int option);
        Node(int size, int **grid, int g, char move, Node *parent, int a, int b);
        ~Node();
        void    displayGrid(int **grid) const;
        int     **getFinalGrid() const;
        int     **getGrid() const;
        int     getG() const;
        int     getF() const;
        int     getH() const;
        void    setH(int value);
        char    getHeuristic() const;
        void    expand(std::priority_queue<Node*, std::vector<Node*>, Comparator>& opened, std::set<std::string>& closed, std::list<Node*>& used);
        void    calculateH();
        void    misplacedTiles();
        void    manhattanDistance();
        void    linearConflict();
        std::string    getHash() const;
        void    createHash();
        std::string    createFinalHash();
        Node*    getParent() const;


    private:

        int         _size;
        int         **_grid;
        Node*       _parent;
        int         _g;
        int         _h;
        std::string _hash;
        int         **createFinalGrid();
        int         **createFirstGrid(std::vector<int> numbers);
        void        findZero(int &a, int &b, std::string &move);
        void        findPos(int &a, int &b, int num);
        bool        findConflicts(int a, int b, int &conflicts);
};

static int  **_finalGrid;
static char _heuristic;
static int  _option;

bool     parser(char* fileName, size_t& size, std::vector<int>& numbers);
bool     solvableTest(std::vector<int> numbers, int size);
int      checkOption(char **argv, int argc);
char     checkHeuristic(char **argv, int argc);

class Comparator {
    public:
    bool operator()(const Node* a, const Node* b) const {
        return (a->getF() > b->getF());
    }
};

#endif
#include "Node.hpp"

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int         main(int argc, char ** argv) {

    if (argc < 2) {
        std::cout << "Usage: ./npuzzle -heuristic[-M/m,-L/l,-T/t](optional) -option[-g,-h](optional) puzzle.txt" << std::endl;
        return 0;
    }

    int option = 0;
    char heuristic = 'L';
    if (argc > 1) {
        heuristic = checkHeuristic(argv, argc);
        option = checkOption(argv, argc);
    }
    size_t      size;
    std::vector<int> numbers; 
    size_t      maxSize = 0;

    if (!parser(argv[argc - 1], size, numbers))
        return 0;

    if (!solvableTest(numbers, size)) {
        std::cout << "This npuzzle is unsolvable" << std::endl;
        return 0;
    }
    
    Node *firstNode = new Node(size, numbers, heuristic, option);
    std::priority_queue<Node*, std::vector<Node*>, Comparator> opened;

    std::set<std::string> closed;
    std::list<Node *> used;
    std::list<Node *> solvedPath;
    std::string finalHash = firstNode->createFinalHash();
    struct timeval starts;
    int         movesNumber;
    struct timeval ends;

    opened.push(firstNode);
    firstNode->expand(opened, closed, used);

    gettimeofday(&starts, NULL);
    long int start = starts.tv_sec * 1000 + starts.tv_usec / 1000;

    while(finalHash != opened.top()->getHash()) {
        opened.top()->expand(opened, closed, used);
        maxSize = (opened.size() > maxSize) ? opened.size() : maxSize;
    }

    gettimeofday(&ends, NULL);
    long int end = ends.tv_sec * 1000 + ends.tv_usec / 1000;

    solvedPath.push_back(opened.top());

    while (solvedPath.front()->getParent() != NULL) {
        solvedPath.push_front(solvedPath.front()->getParent());
    }

    movesNumber = solvedPath.size();

    while (solvedPath.size() > 0) {
        solvedPath.front()->displayGrid(solvedPath.front()->getGrid());
        std::cout << std::endl;
        solvedPath.pop_front();
    }   

    std::cout << "Complexity in time: " << (end - start) / 1000 << "." << (end - start) % 1000 << "s" << std::endl;
    std::cout << "Complexity in size: " << maxSize << std::endl;
    std::cout << "Number of moves: " << movesNumber << std::endl;
    std::cout << "Heuristic used: " << 
    (heuristic == 'L' ? "Linear Conflict" : 
    heuristic == 'M' ? "Manhattan-distance" :
    heuristic == 'T' ? "Misplaced Tiles" : "") 
    << std::endl;

    while (!opened.empty()) {
        delete opened.top();
        opened.pop();
    }
    while (!used.empty()) {
        delete used.front();
        used.pop_front();
    }
    delete firstNode; 

    return 0;
}

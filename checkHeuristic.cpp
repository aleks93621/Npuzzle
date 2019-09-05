#include "Node.hpp"

char checkHeuristic(char **argv, int argc) {
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i] && argv[i][0] == '-' && argv[i][1]) {
            if ((argv[i][1] == 'L' || argv[i][1] == 'l') && !argv[i][2])
                return 'L';
            else if ((argv[i][1] == 'T' || argv[i][1] == 't') && !argv[i][2])
                return 'T';
            else if ((argv[i][1] == 'M' || argv[i][1] == 'm') && !argv[i][2])
                return 'M';
        }
    }

    return 'L';
}
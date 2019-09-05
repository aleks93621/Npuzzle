#include "Node.hpp"

int checkOption(char **argv, int argc) {
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i] && argv[i][0] == '-' && argv[i][1]) {
            if (argv[i][1] == 'g' && !argv[i][2])
                return 1;
            else if (argv[i][1] == 'h' && !argv[i][2])
                return 2;
        }
    }

    return 0;
}
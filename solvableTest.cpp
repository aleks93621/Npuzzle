#include "Node.hpp"

bool       solvableTest(std::vector<int> numbers, int size) {

    int     i, j;
    int     progress = 0;
    std::vector<int> snailNumbers;
    size_t mismatch = 0;

    while (progress < size / 2 + 1) {
        i = progress;
        j = progress + 1;

        while (i < size - progress) {
            snailNumbers.push_back(numbers.at(progress * size + i));                    
            i++;
        }
        while (j < size - progress) {
            snailNumbers.push_back(numbers.at(size * j + size - 1 - progress));
            j++;
        }
        i = i - 2;
        j = j - 2;
        while (i >= progress) {
            snailNumbers.push_back(numbers.at(size * (size - progress - 1) + i));
            i--;
        }
        while (j > progress) {
            snailNumbers.push_back(numbers.at(size * j + progress));
            j--;
        }
        progress++;
    }
    
    for (int a = 1; a < size * size - 1; a++) {
        i = 0;
        while (snailNumbers.at(i) != a) {
            if (snailNumbers.at(i) > a)
                mismatch++;
            i++;
        }
    }
    return mismatch % 2 == 0;
}
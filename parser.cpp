#include "Node.hpp"


bool     parser(char* fileName, size_t& size, std::vector<int>& numbers) {

    std::string line;
    std::ifstream myfile(fileName);
    if (!myfile) {
        std::cout << "Mauvais fichier texte, c'est confirmé." << std::endl;
        return false;
    }
    size_t nbLines = 0;
    int temp;
    std::vector<int>::iterator it;

    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {

            if (line[0] != '#' && line.length() > 0) {
                if (line.find_first_of('#') != std::string::npos)
                    line = line.substr(0, line.find_first_of('#'));

                if (nbLines == 0) {
                    for (size_t i = 0; i < line.size(); i++) {
                        if (!isnumber(line[i])) {
                            std::cout << "The first line is not a positive number" << std::endl;
                            return false;
                        }
                    }
                    size = std::atoi(line.c_str());                    
                    if (size < 3) {
                        std::cout << "The first line is not a number above 2" << std::endl;
                        return false;
                    }
                } else {
                    std::stringstream ss(line);
                    while (ss >> temp) {
                        if (temp < 0 || temp >= (int)(size * size)) {
                            std::cout << "The numbers are not all in the range [0, size - 1]: " << temp << std::endl;
                            return false;
                        }
                        it = find(numbers.begin(), numbers.end(), temp);
                        if (it != numbers.end()) {
                            std::cout << "Some values are duplicated: " << temp << std::endl;
                            return false;
                        }
                        numbers.push_back(temp);
                    }

                    if (numbers.size() % size != 0) {
                        std::cout << "All the line do not have the good amount of numbers" << std::endl;
                        return false;
                    }
                }
                nbLines++;
            }
        }
        if (nbLines - 1 != size) {
            std::cout << "The number of lines is not equal to the size" << std::endl;
            return false;
        }
        if (numbers.size() != size * size) {
            std::cout << "The number of lines is not equal to the size" << std::endl;
            return false;
        }
    }
    return true;
}

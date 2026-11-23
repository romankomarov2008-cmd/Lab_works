#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    std::string filename = "data.txt";
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cout << "Could not open file " << filename << std::endl;
        return 1;
    }

    std::vector<int> positiveNumbers;
    std::string line;

    while (std::getline(inFile, line)) {
        for (char& c : line) {
            if (c == ',') {
                c = ' ';
            }
        }

        std::stringstream ss(line);
        int number;
        while (ss >> number) {
            if (number > 0) {
                positiveNumbers.push_back(number);
            }
        }
    }
    inFile.close();

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cout << "Could not open file " << filename << std::endl;
        return 1;
    }

    for (size_t i = 0; i < positiveNumbers.size(); ++i) {
        outFile << positiveNumbers[i];
        if (i + 1 < positiveNumbers.size()) {
            outFile << " ";
        }
    }

    outFile.close();
    std::cout << "File is successfully overwritten" << std::endl;
    return 0;
}
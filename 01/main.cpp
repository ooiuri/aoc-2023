/* ooiuri :) */

#include <iostream>
#include <fstream>
#include <string>

bool isDigit(char character) {
    if (character >= '0' && character <= '9') {
        return true;
    }
    return false;
}

int parseNumber(std::string line) {
    char first, last;
    const char *str = line.c_str();
    for (int i = 0; i < line.length(); i++) {
        if(isDigit(str[i])){
            first = str[i];
            break;
        }
    }
    for (int i = line.length(); i >= 0; i--) {
        if(isDigit(str[i])){
            last = str[i];
            break;
        }
    }
    char result[3];
    sprintf(result, "%c%c", first, last);
    return std::atoi(result);
}

int main() {

    printf("Hello Advent! - 01\n");
    std::ifstream inputFile("input.txt"); 
    int result = 0;
    if (inputFile.is_open()) { 
        std::string line;
        while (std::getline(inputFile, line)) { 
            result += parseNumber(line);
        }
        inputFile.close(); 
    } else {
        printf("Erro ao abrir! \n");
    }

    printf("result: %d\n", result);
}

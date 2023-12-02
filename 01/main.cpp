/* ooiuri :) */

#include <iostream>
#include <fstream>
#include <string>

std::string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

bool isDigit(char character)
{
    if (character >= '0' && character <= '9')
    {
        return true;
    }
    return false;
}

int parseNumber(std::string line)
{
    char first, last;
    const char *str = line.c_str();
    for (int i = 0; i < line.length(); i++)
    {
        if (isDigit(str[i]))
        {
            first = str[i];
            break;
        }
    }
    for (int i = line.length(); i >= 0; i--)
    {
        if (isDigit(str[i]))
        {
            last = str[i];
            break;
        }
    }
    char result[3];
    sprintf(result, "%c%c", first, last);
    return std::atoi(result);
}

int findNumber (std::string line) {
    int firstPos = line.length();
    int lastPos = -1;
    char first, last;
    const char* linech = line.c_str();
    
    for(int i = 0; i < 10; i++){
        size_t pos = line.find(numbers[i]);
        if (pos != std::string::npos) {
            if( pos < firstPos) {
                firstPos = pos;
                first = '0' + i; 
            }
        }
    }
    for(int i = 0; i < 10; i++){
        size_t found = line.find(numbers[i]);
        size_t pos = std::string::npos;

        while (found != std::string::npos) {
            pos = found;
            found = line.find(numbers[i], found + 1);
        }
        if (pos != std::string::npos) {
            if( pos > lastPos || lastPos == -1) {
                printf("entrei\n");

                lastPos = pos;
                last = '0' + i; 
            }
        }
    }

    for(int i = 0; i < line.length(); i++){
        if (isDigit(linech[i])){
            if( i < firstPos) {
                firstPos = i;
                first = linech[i];
            }
            if( i > lastPos) {
                lastPos = i;
                last = linech[i];
            }
        }
        
    }

    char result[3];
    sprintf(result, "%c%c", first, last);
    return std::atoi(result);
}

int main()
{

    printf("Hello Advent! - 01\n");
    std::ifstream inputFile("input.txt");
    int result = 0;
    if (inputFile.is_open())
    {
        std::string line;
        int i = 1;
        while (std::getline(inputFile, line))
        {   
            int n = findNumber(line);
            printf("%d\n", n);
            result += n;
            i++;
        }
        inputFile.close();
    }
    else
    {
        printf("Erro ao abrir! \n");
    }

    printf("\nresult: %d\n", result);
}

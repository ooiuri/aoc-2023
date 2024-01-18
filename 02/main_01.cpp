/* ooiuri :) */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int returnDigits(const char* line){
    std::string str(line);
    std::string out;
    for(int i = 0; i < str.length(); i++){
        if(str.c_str()[i] >= '0' && str.c_str()[i] <= '9'){
            out += str.c_str()[i];
        }
    }
    return std::stoi(out);
}

int parseLine(const char* line, int &index, int &nBlue, int &nRed, int &nGreen) {
    printf("Recebi %s\n", line);
    std::string str(line);
    std::string game;
    // split ":"
    size_t gamePos = str.find(":");
    if (gamePos != std::string::npos) {
        game = str.substr(0, gamePos);
        printf("Game: %s\n", game.c_str());
    }
    std::string plays[5]; //dynamic allocated would be beautiful
    int nPlays = 0;
    size_t playsPos = gamePos + 1;
    size_t nextPos = 0;
    // split plays into plays array
    while (nextPos != std::string::npos) {
        nextPos = str.find(";", playsPos);
        if (nextPos != std::string::npos){
            plays[nPlays] = str.substr(playsPos, nextPos - playsPos);
        }
        else {
            plays[nPlays] = str.substr(playsPos, str.length());
        }
        playsPos = nextPos + 1;
        nPlays++;
    }

    for (const auto& play : plays) {
        printf("auto: %s \n", play.c_str());
        if
    }
    printf("ffdsa465 -> %d", returnDigits("ffdsa465"));
    return 0;
}

int main () {

    const char* line = "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red";
    int index, nBlue, nRed, nGreen;
    parseLine(line, index, nBlue, nRed, nGreen);
    return 0;
}
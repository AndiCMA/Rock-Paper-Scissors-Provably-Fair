#pragma once
#include <string>

class Game {
public:
    Game();
    void run();
private:
    int nonce;
    void playRound();
    int getPlayerChoice();
    std::string toString(int choice);
};

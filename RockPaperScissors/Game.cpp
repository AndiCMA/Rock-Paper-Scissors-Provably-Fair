#include "Game.h"
#include "SeedManager.h"
#include "ProvablyFair.h"
#include <iostream>

enum RPS {
	ROCK = 0,
	PAPER = 1,
	SCISSORS = 2
};

Game::Game() : nonce(0) {}

std::string Game::toString(int choice) {
    switch (choice) {
    case ROCK: return "Rock";
    case PAPER: return "Paper";
    case SCISSORS: return "Scissors";
    default: return "Unknown";
    }
}

int Game::getPlayerChoice() {
    int choice;
    std::cout << "Choose [0] Rock, [1] Paper, [2] Scissors: ";
    std::cin >> choice;
    while (choice < 0 || choice > 2) {
        std::cout << "Invalid. Try again: ";
        std::cin >> choice;
    }
    return choice;
}

void Game::playRound() {
    int player = getPlayerChoice();
    int computer = ProvablyFair::generate(&nonce);

    std::cout << "You: " << toString(player)
        << " | Computer: " << toString(computer) << "\n";

    if (player == computer)
        std::cout << "It's a draw!\n";
    else if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER))
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";

    ++nonce;
}

void Game::run() {
    SeedManager* seedMgr = SeedManager::getInstance();
    seedMgr->initServerSeed();

    std::string clientSeed;
    std::cout << "Enter your client seed (string): ";
    std::cin >> clientSeed;
    seedMgr->setClientSeed(clientSeed);

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        playRound();
        std::cout << "Play again? (y/n): ";
        std::cin >> again;
    }

    std::cout << "Server seed (for verification): " << *seedMgr->getServerSeed() << "\n";
}
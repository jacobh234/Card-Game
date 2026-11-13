/*
Adv. Programming, B8, Mr. Test
10/29/26
[your name here]
*/

#include <iostream>
#include "PlayingCard.h"
#include "DeckOfCards.h"
#include "Player.h"
#include "BS.h"

int main()
{
    BS game(2); // Creates a 2-player game, deals cards, sets rank to Ace (1)

    while (!game.checkWinner()) {
        int activePlayer = game.getCurrentTurn();
        std::cout << "Player " << activePlayer << "'s turn. Required rank: " 
                  << game.getCurrentRank() << "\n";

        // 1. Active player picks a card to put down
        int cardChoice;
        std::cout << "Pick card index to place face down: ";
        std::cin >> cardChoice;
        game.playTurn(cardChoice);

        // 2. Opponent gets the option to press 1 for BS
        int challenge;
        std::cout << "Opponent: Press 1 to call BS, or 0 to continue: ";
        std::cin >> challenge;

        if (challenge == 1) {
            bool wasLying = game.callBS();
            if (wasLying) {
                std::cout << "Caught! Player " << activePlayer << " takes the pile.\n";
            } else {
                std::cout << "Truth! Challenger takes the pile.\n";
            }
        }

        game.nextTurn(); // Moves to next player and increments required rank
    }

    std::cout << "Game Over!\n";
    return 0;
}

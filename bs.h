#pragma once

#include "Pile.h"
#include "Player.h"
#include "DeckOfCards.h"

class BS
{
private:
    Player player1;
    Player player2;
    DeckOfCards deck;
    Pile pile;
    int realRank = 0;
    int playerChoice;
    int currentPlayer = 1;
public:
    void playerTurn(Player& player);
    BS();
    void startGame();

};
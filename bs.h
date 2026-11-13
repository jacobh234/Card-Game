#pragma once
#include <vector>
#include "Player.h"
#include "Pile.h"
#include "DeckOfCards.h"

class BS {
private:
    int currentRank;
    int currentTurn;
    int numPlayers;
    int pileSize;

    Pile centerPile;
    std::vector<Player> players;

public:
    BS(int numPlayers);

    // Getters and Setters from your UML
    int getCurrentRank() const;
    void setCurrentRank(int rank);
    int getCurrentTurn() const;
    void setCurrentTurn(int turn);
    int getNumPlayers() const;
    void setNumPlayers(int num);
    int getPileSize() const;
    void setPileSize(int size);

    // Core Game Functions from your UML
    void playTurn(int cardIndex);
    bool callBS();
    void nextTurn();
    bool checkWinner() const;
};

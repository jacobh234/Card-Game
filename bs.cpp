#include "BS.h"

BS::BS(int numPlayers) {
    this->numPlayers = numPlayers;
    this->currentRank = 1;
    this->currentTurn = 0;
    this->pileSize = 0;

    DeckOfCards deck;
    deck.shuffle();

    for (int i = 0; i < numPlayers; i++) {
        players.push_back(Player());
    }

    int pIndex = 0;
    for (int i = 0; i < 52; i++) {
        players[pIndex].draw(deck.deal());
        pIndex = (pIndex + 1) % numPlayers;
    }
}

int BS::getCurrentRank() const { return currentRank; }
void BS::setCurrentRank(int rank) { currentRank = rank; }

int BS::getCurrentTurn() const { return currentTurn; }
void BS::setCurrentTurn(int turn) { currentTurn = turn; }

int BS::getNumPlayers() const { return numPlayers; }
void BS::setNumPlayers(int num) { numPlayers = num; }

int BS::getPileSize() const { return centerPile.size(); }
void BS::setPileSize(int size) { pileSize = size; }

void BS::playTurn(int cardIndex) {
    PlayingCard playedCard = players[currentTurn].removeCard(cardIndex);
    centerPile.addCard(playedCard);
    pileSize = centerPile.size();
}

bool BS::callBS() {
    PlayingCard topCard = centerPile.getTopCard();
    std::vector<PlayingCard> dumpedCards = centerPile.takeAll();
    pileSize = 0;

    if (topCard.getRank() != currentRank) {
        for (PlayingCard c : dumpedCards) {
            players[currentTurn].draw(c);
        }
        return true; 
    } else {
        int challenger = (currentTurn + 1) % numPlayers;
        for (PlayingCard c : dumpedCards) {
            players[challenger].draw(c);
        }
        return false;
    }
}

void BS::nextTurn() {
    currentTurn = (currentTurn + 1) % numPlayers;
    currentRank++;
    if (currentRank > 13) {
        currentRank = 1;
    }
}

bool BS::checkWinner() const {
    return players[currentTurn].getHandSize() == 0;
}

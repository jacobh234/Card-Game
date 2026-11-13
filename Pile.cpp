#include "Pile.h"

void Pile::addCard(PlayingCard c) {
    cards.push_back(c);
}

PlayingCard Pile::getTopCard() const {
    return cards.back();
}

std::vector<PlayingCard> Pile::takeAll() {
    std::vector<PlayingCard> allCards = cards;
    cards.clear();
    return allCards;
}

int Pile::size() const {
    return cards.size();
}

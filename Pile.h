#pragma once
#include <vector>
#include "PlayingCard.h"

class Pile {
private:
    std::vector<PlayingCard> cards;

public:
    void addCard(PlayingCard c);
    PlayingCard getTopCard() const;
    std::vector<PlayingCard> takeAll();
    int size() const;
};

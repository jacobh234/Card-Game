#pragma once
#include <vector>
#include "playingCard.h"

class Pile
{
    private:
        std::vector<PlayingCard> cards;
    public:
        Pile();
        void addCard(PlayingCard card);

        //i spent 20 minutes on here arguing with chatgpt why bjarn decided to require you return the contents rather than the name
        //return cards wouldve logically made more sense
        // 1st reason pythons better
        std::vector<PlayingCard> grabPile();
};
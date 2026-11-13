#pragma once
#include<string>
#include<vector>
#include<ctime>
#include"PlayingCard.h"

class DeckOfCards
{
private:
    std::vector<PlayingCard> drawFrom;
    std::vector<PlayingCard> dealt;
public:
    DeckOfCards();
    std::string stringify() const;
    std::vector<PlayingCard> getDealt() const;
    std::vector<PlayingCard> getDrawFrom() const;
    void shuffle();
    PlayingCard deal();
};

#include "pile.h"

Pile::Pile()
{}

void Pile::addCard(PlayingCard card)
{
    cards.push_back(card);
}

std::vector<PlayingCard> Pile::grabPile() 
{
    return cards;
}
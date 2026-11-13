//
// Created by Benjamin Test on 12/18/24.
//

#include "Player.h"

Player::Player()
{
    hand = std::vector<PlayingCard>();
}

std::string Player::str() const
{
    std::string cards = "";
    for (int i = 0; i < hand.size(); ++i)
    {
        cards = cards + hand.at(i).stringify() + "\n";
    }
    return cards;
}

std::vector<PlayingCard> Player::getHand() const
{
    return hand;
}

void Player::draw(PlayingCard dr)
{
    hand.push_back(dr);
}

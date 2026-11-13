//
// Created by Benjamin Test on 12/18/24.
//

#pragma once
#include<Vector>
#include"PlayingCard.h"
#include<string>



class Player
{
private:
    std::vector<PlayingCard> hand;
public:
    Player();
    std::string str() const;
    void draw(PlayingCard);
    std::vector<PlayingCard> getHand() const;
    int getHandSize() const;
    PlayingCard removeCard(int index);

};


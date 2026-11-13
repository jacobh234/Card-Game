/*
Demonstration of the playing card class and classes
that use the playing card
Adv. Programming, B8, Mr. Test
10/29/26
[your name here]
Written together as a class
*/

#include <iostream>
#include"PlayingCard.h"
#include"DeckOfCards.h"
#include"Player.h"

int main()
{
    std::vector<Player> game = std::vector<Player>();
    game.push_back(Player());
    game.push_back(Player());

    DeckOfCards theDeck = DeckOfCards();
    theDeck.shuffle();

    for (int i = 0; i < 5; ++i)
    {
        game.at(0).draw(theDeck.deal());
        game.at(1).draw(theDeck.deal());
    }

    std::cout << "Player 1:" << std::endl;
    std::cout << game.at(0).str() << std::endl;
    std::cout << "Player 2:" << std::endl;
    std::cout << game.at(1).str() << std::endl;


    return 0;
}

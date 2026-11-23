
#include "bs.h"
#include <iostream>
#include <cstdlib>

BS::BS()
{
}

void BS::startGame()
{
    //shffles deck and deals
    deck.shuffle();

    for (int i = 0; i < 26; i++)
    {
        player1.draw(deck.deal());
        player2.draw(deck.deal());
    }

    realRank = 2;
    currentPlayer = 1;

    //winning and whatever
    while (player1.getHandSize() > 0 && player2.getHandSize() > 0)
    {
        if (currentPlayer == 1)
        {
            playerTurn(player1);
        }
        else
        {
            playerTurn(player2);
        }
    }

    if (player1.getHandSize() == 0)
    {
        std::cout << "Player 1 wins!" << std::endl;
    }
    else
    {
        std::cout << "Player 2 wins!" << std::endl;
    }
}

void BS::playerTurn(Player& player)
{

    std::cout << "\nYour hand:\n";
    std::cout << player.str() << std::endl;

    Player& opponent = (currentPlayer == 1) ? player2 : player1;

    int playerNumber = currentPlayer;
    int opponentNumber = (currentPlayer == 1) ? 2 : 1;

    std::cout << "Player " << playerNumber << ", the current card is " << realRank
              << ". Press 1 to play the real card or 2 to play a lie." << std::endl;

    std::cin >> playerChoice;

    std::vector<PlayingCard> hand = player.getHand();

    //truth or lie
    if (playerChoice == 1)
    {
        std::vector<int> matchingCards;

        for (int i = 0; i < hand.size(); i++)
        {
            if (hand.at(i).getRank() == realRank)
            {
                matchingCards.push_back(i);
            }
        }

        if (matchingCards.size() > 0)
        {
            int randomIndex = rand() % matchingCards.size();
            int cardIndex = matchingCards.at(randomIndex);

            PlayingCard playedCard = player.removeCard(cardIndex);
            pile.addCard(playedCard);
        }
        else
        {
            int randomIndex = rand() % hand.size();

            PlayingCard playedCard = player.removeCard(randomIndex);
            pile.addCard(playedCard);
        }
    }
    else
    {
        int randomIndex = rand() % hand.size();

        PlayingCard playedCard = player.removeCard(randomIndex);
        pile.addCard(playedCard);
    }

    //switch sides
    std::cout << "Player " << opponentNumber
              << ", Player " << playerNumber
              << " has played. Press 1 to call BS or 2 to take your turn."
              << std::endl;

    //call bs
    std::cin >> playerChoice;

    if (playerChoice == 1)
    {
        std::vector<PlayingCard> playedCards = pile.grabPile();

        if (playedCards.back().getRank() != realRank)
        {
            std::cout << "Player " << playerNumber << " lied! They pick up the pile." << std::endl;

            for (PlayingCard card : playedCards)
            {
                player.draw(card);
            }
        }
        else
        {
            std::cout << "Player " << playerNumber << " told the truth! Player "
                      << opponentNumber << " picks up the pile." << std::endl;

            for (PlayingCard card : playedCards)
            {
                opponent.draw(card);
            }
        }
    }

    realRank++;

    if (realRank > 14)
    {
        realRank = 2;
    }

    currentPlayer = opponentNumber;
}

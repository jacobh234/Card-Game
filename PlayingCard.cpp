#include"PlayingCard.h"

const std::string PlayingCard::BRAND = "Bicycle";

PlayingCard::PlayingCard()
{
    rank = 14;
    suit = 3;
}

PlayingCard::PlayingCard(int r, int s)
{
    rank = r;
    suit = s;
}

int PlayingCard::getRank() const
{
    return rank;
}

int PlayingCard::getSuit() const
{
    return suit;
}

void PlayingCard::setRank(int r)
{
    rank = r;
}

void PlayingCard::setSuit(int s)
{
    suit = s;
}

bool PlayingCard::getRed() const
{
    return (suit == 1 || suit == 2);
}

bool PlayingCard::getFace() const
{
    return (rank == 11 || rank == 12 || rank == 13);
}

std::string PlayingCard::stringify() const
{
    std::string ranks[] = {"null", "null", "Two", "Three", "Four",
                        "Five", "Six", "Seven", "Eight", "Nine",
                        "Ten", "Jack", "Queen", "King", "Ace"};
    std::string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    return ranks[rank] + " of " + suits[suit];
 }

 std::string PlayingCard::getBrand()
 {
    return BRAND;
 }

 bool PlayingCard::operator<(const PlayingCard& rho) const
 {
    return (rank < rho.getRank());
 }

 bool PlayingCard::operator<=(const PlayingCard& rho) const
 {
    return (rank <= rho.getRank());
 }

 bool PlayingCard::operator>(const PlayingCard& rho) const
 {
    return (rank > rho.getRank());
 }

 bool PlayingCard::operator>=(const PlayingCard& rho) const
 {
    return (rank >= rho.getRank());
 }

bool PlayingCard::operator==(const PlayingCard& rho) const
 {
    return (rank == rho.getRank());
 }

 bool PlayingCard::operator!=(const PlayingCard& rho) const
 {
    return (rank != rho.getRank());
 }
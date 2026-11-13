#pragma once
#include<string>

class PlayingCard
{
private:
    int rank;
    int suit;
    const static std::string BRAND;

public:
    //constructors
    PlayingCard();
    PlayingCard(int, int);
    //getters
    int getRank() const;
    int getSuit() const;
    //setters
    void setRank(int);
    void setSuit(int);
    //get red method, returns a bool whether card is red or not
    bool getRed() const;
    //get face method, returns bool whether card is face or not
    bool getFace() const;
    //stringify returns string description of state of object
    std::string stringify() const;
    //Static method that returns brand of cards
    static std::string getBrand();

    // Think of + ... 6 + 7 => 13, "foo" + "bar" => "foobar"
    // We will overload relational operators
    // Overloaded operators are invoked on the left hand operand (LHO)
    // with the right hand operand (RHO) is passed as an argument
    bool operator<(const PlayingCard&) const;
    bool operator<=(const PlayingCard&) const;
    bool operator>(const PlayingCard&) const;
    bool operator>=(const PlayingCard&) const;
    bool operator==(const PlayingCard&) const;
    bool operator!=(const PlayingCard&) const;
};
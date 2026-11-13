#include"DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 2; j < 15; ++j)
        {
            drawFrom.push_back(PlayingCard(j, i));
        }
    }
}

std::string DeckOfCards::stringify() const
{
    std::string strOut = "To Draw:\n";
    for (int i = 0; i < drawFrom.size(); ++i)
    {
        strOut += (drawFrom.at(i).stringify() + "\n");
    }
    strOut += "\nDealt:\n";
    for (int i = 0; i < dealt.size(); ++i)
    {
        strOut += (dealt.at(i).stringify() + "\n");
    }
    return strOut;
}

std::vector<PlayingCard> DeckOfCards::getDealt() const
{
    return dealt;
}

std::vector<PlayingCard> DeckOfCards::getDrawFrom() const
{
    return drawFrom;
}

void DeckOfCards::shuffle()
{
    srand(time(0));
    int index = 0;
    while (drawFrom.size() > 0)
    {
        index = rand() % drawFrom.size();
        dealt.push_back(drawFrom.at(index));
        drawFrom.erase(drawFrom.begin() + index);
    }

    while (dealt.size() > 0)
    {
        index = rand() % dealt.size();
        drawFrom.push_back(dealt.at(index));
        dealt.erase(dealt.begin() + index);
    }
}

PlayingCard DeckOfCards::deal()
{
    PlayingCard toDeal = drawFrom.at(drawFrom.size() - 1);
    dealt.push_back(toDeal);
    drawFrom.pop_back();
    return toDeal;
}
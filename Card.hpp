#include <iostream>

#ifndef CARD_H
#define CARD_H
class Card
{
public:
    Card();
    Card(int value, std::string suit);

    int getValue() const;
    std::string getSuit() const;

    void setValue(int value);
    void setSuit(std::string suit);

    void printCard() const;
private:
    int value_;
    std::string suit_;
};
#endif
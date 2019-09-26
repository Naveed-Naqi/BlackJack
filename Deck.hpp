#include "Card.hpp"
#include <array>

#ifndef DECK_H
#define DECK_H
class Deck
{
public:
    Deck();
    void shuffle();
    void printDeck() const;
    Card operator[](size_t index);
private:
    std::array<Card, 52> deck_;
};
#endif
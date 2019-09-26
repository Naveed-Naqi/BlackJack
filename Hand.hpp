#include "Card.hpp"
#include<vector>

#ifndef HAND_H
#define HAND_H
class Hand
{
public:
    Hand();

    int getSum() const;
    void addCard(const Card& new_card);

    Card operator[](size_t index) const;
    int size();

    bool containsAce() const;
    void flipAceVal(); 
private:
    int sum_;
    std::vector<Card> cards_in_hand_;
};
#endif
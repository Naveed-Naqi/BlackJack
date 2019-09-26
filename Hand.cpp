#include "Hand.hpp"

Hand::Hand() : sum_(0) {};

int Hand::getSum() const { return sum_; }

void Hand::addCard(const Card& new_card)
{
    cards_in_hand_.push_back(new_card);
    sum_+= new_card.getValue();
}

Card Hand::operator[](size_t index) const
{
    return cards_in_hand_[index];
}

int Hand::size()
{
    return cards_in_hand_.size();
}


bool Hand::containsAce() const
{
    for(Card card : cards_in_hand_)
    {
        if (card.getValue() == 1 || card.getValue() == 11)
        {
            return true;
        }
    }

    return false;
}

void Hand::flipAceVal()
{
    for(Card card : cards_in_hand_)
    {
        if (card.getValue() == 1)
        {
            card.setValue(11);
        }
        else
        {
            card.setValue(1);
        }
    }
        
}

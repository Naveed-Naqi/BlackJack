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

void Hand::flipAceVal(int index)
{
    if (cards_in_hand_[index].getValue() == 1)
    {
        cards_in_hand_[index].setValue(11);
    }
    else
    {
        cards_in_hand_[index].setValue(1);
    }     
}

#include "Card.hpp"

Card::Card() : value_(0), suit_("") {};

Card::Card(int value, std::string suit) : value_(value), suit_(suit) {};

int Card::getValue() const { return value_; }

std::string Card::getSuit() const { return suit_; }

void Card::setSuit(std::string suit) { suit_ = suit; }

void Card::setValue(int value) { value_ = value; }

void Card::printCard() const
{
    if(value_ == 1 || value_ == 11) 
    {
       std::cout << " Ace of " << suit_ << "\t"; 
    }
    else
    {
        std::cout << value_ << " of " << suit_ << "\t";   
    }
}
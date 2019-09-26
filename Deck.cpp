#include "Deck.hpp"

#include <algorithm>
#include <chrono>
#include <random>
#include <iterator>

Deck::Deck()
{
    std::string suits[4] = {"diamonds", "hearts", "clovers", "spades"};
    
    int curr_card_in_deck = 0;

    //initializing all other cards
    for(int curr_card_val = 1; curr_card_val <= 9; curr_card_val++)
    {
        for(int curr_suit = 0; curr_suit <= 3; curr_suit++)
        {
            deck_[curr_card_in_deck].setValue(curr_card_val);
            deck_[curr_card_in_deck].setSuit(suits[curr_suit]);
            curr_card_in_deck++;
        }
    }

    //initializing the face cards
    for(int curr_face_card = 0; curr_face_card <= 3; curr_face_card++)
    {
        for(int curr_suit = 0; curr_suit <= 3; curr_suit++)
        {
            deck_[curr_card_in_deck].setValue(10);
            deck_[curr_card_in_deck].setSuit(suits[curr_suit]);
            curr_card_in_deck++;
        }
    }

    shuffle();
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(deck_.begin(), deck_.end(), g);
}

Card Deck::operator[](size_t index)
{
    return deck_[index];
}

void Deck::printDeck() const
{
    for(int i = 0; i < deck_.size(); i++)
    {
        deck_[i].printCard();
    }
}
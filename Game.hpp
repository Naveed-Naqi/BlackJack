#include "Hand.hpp"
#include "Deck.hpp"

class Game
{
public:
    Game();
    void startGame();
    std::string changeToUpperCase(std::string some_string);
private:
    Hand player_hand_;
    Hand dealer_hand_;
    Deck deck_;
    int curr_top_deck_;

    int index_of_player_ace_;
    int index_of_dealer_ace_;

    void determineWinner();
    void dealCards();

    void displayPlayerHand();
    void displayDealerHand();
    void revealDealerHand();

    void delay();

};
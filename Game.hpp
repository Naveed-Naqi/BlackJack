#include "Hand.hpp"
#include "Deck.hpp"

class Game
{
public:
    Game();
    void startGame();
private:
    Hand player_hand_;
    Hand dealer_hand_;
    Deck deck_;
    int curr_top_deck_;

    bool player_has_ace_;
    bool dealer_has_ace_;

    void determineWinner();
    void dealCards();

    void displayPlayerHand();
    void displayDealerHand();
    void revealDealerHand();

    void delay();

};
#include "Game.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <locale>

Game::Game() : curr_top_deck_(0)
{
    dealCards();

    index_of_player_ace_ = -1;
    index_of_dealer_ace_ = -1;
}

std::string Game::changeToUpperCase(std::string some_string)
{
    std::locale loc;
    std::string new_string = "";

    for(char letter : some_string)
    {
        new_string += std::toupper(letter, loc);
    }

    return new_string;
}

void Game::delay()
{
    using namespace std::chrono;
    using namespace std::this_thread;

    sleep_until(system_clock::now() + seconds(1));
}

void Game::startGame()
{
   std::cout << "Welcome to Blackjack! Press 'H' to hit and 'P' to pass and press 'F' to flip the value of an Ace (not case sensitive)\n";

   bool game_over = false;
   std::string player_reponse = "";

    displayDealerHand();
    displayPlayerHand();

   while(!game_over)
   {
        std::cin >> player_reponse;

        if(changeToUpperCase(player_reponse) == "H")
        {
            player_hand_.addCard(deck_[curr_top_deck_]);

            if(index_of_player_ace_ != -1 && deck_[curr_top_deck_].getValue() == 1) 
            {
                index_of_player_ace_ = player_hand_.size()-1;
            }

            curr_top_deck_++;
            displayPlayerHand();

            if(player_hand_.getSum() > 21)
            {
                game_over = true;
            }
        }

        else if(changeToUpperCase(player_reponse) == "P")
        {
            game_over = true;
        }
        else if(changeToUpperCase(player_reponse) == "F")
        {
            if(index_of_player_ace_ != -1)
            {
                if(player_hand_.getSum() + 10 > 21)
                {
                    std::cout << "You will lose the game if you flip the value of your ace.\n";
                }
                else
                {
                    player_hand_.flipAceVal(index_of_player_ace_);
                    displayPlayerHand();
                }

            }
            else
            {
                std::cout << "You do not have an ace in hand \n";
            }
        }
        else
        {
            std::cout << "That is not a valid input, please try again\n";
            std::cout << "Press 'H' to hit and 'P' to pass and press 'F' to flip the value of an Ace (not case sensitive)\n";
        }       
   }

    delay();

    std::cout << "Now the dealer will hit \n";

    while (dealer_hand_.getSum() < 16)
    {
        dealer_hand_.addCard(deck_[curr_top_deck_]);

        if(index_of_dealer_ace_ != -1 && deck_[curr_top_deck_].getValue() == 1) 
        {
            index_of_dealer_ace_ = dealer_hand_.size()-1;
        }

        if(index_of_dealer_ace_ != -1)
        {
            if((dealer_hand_.getSum() + 10) >= 16 && (dealer_hand_.getSum() + 10) <= 21)
            {
                dealer_hand_.flipAceVal(index_of_dealer_ace_);
            }
        }

        delay();
        displayDealerHand();

        curr_top_deck_++;
    }

    delay();
    std::cout << "The dealer has finished hitting and will now reveal their hand: " << std::endl;
    delay();
    revealDealerHand();
    delay();
    displayPlayerHand();
    delay();
    determineWinner();
}

void Game::determineWinner()
{
    bool dealer_lost = false;
    bool player_lost = false;

    int player_score = player_hand_.getSum();
    int dealer_score = dealer_hand_.getSum();

    if(dealer_score > 21)
    {
        dealer_lost = true;
    }
    if(player_score > 21)
    {
        player_lost = true;
    }

    if(player_lost && dealer_lost)
    {
        std::cout << "Its a tie, both of you are above 21 \n";
    }
    else if (player_lost)
    {
        std::cout << "You lost, your sum is a " << player_score << " whereas the dealer's sum is " << dealer_score << "\n";
    }
    else if (dealer_lost)
    {
        std::cout << "You won!, your sum is a " << player_score << " whereas the dealer's sum is " << dealer_score << "\n";
    }
    else
    {
        if(dealer_score == player_score)
        {
            std::cout << "Its a tie! Both of you got " << player_score << "\n"; 
        }
        else if(player_score > dealer_score)
        {
            std::cout << "You won!, your sum is a " << player_score << " whereas the dealer's sum is " << dealer_score << "\n";
        }
        else
        {
            std::cout << "You lost, your sum is a " << player_score << " whereas the dealer's sum is " << dealer_score << "\n";
        }
    }
    
    
}

void Game::dealCards()
{
    for(int i = 0; i < 2; i++)
    {
        player_hand_.addCard(deck_[curr_top_deck_]);

        if(deck_[curr_top_deck_].getValue() == 1)
        {

        }
        curr_top_deck_++;

        dealer_hand_.addCard(deck_[curr_top_deck_]);
        curr_top_deck_++;
    }
}

void Game::displayPlayerHand()
{
    std::cout << "Your hand is as follows: ";

    for(int i = 0; i < player_hand_.size(); i++)
    {
        player_hand_[i].printCard();
    }

    std::cout << "The sum is: " << player_hand_.getSum() << std::endl;
}

void Game::displayDealerHand()
{
    std::cout << "The dealer's hand is follows: ";
    std::cout << "One facedown card, ";

    for(int i = 1; i < dealer_hand_.size(); i++)
    {
        dealer_hand_[i].printCard();
    }

    std::cout << "\n";
}

void Game::revealDealerHand()
{
    std::cout << "The dealers revealed hand is as follows: ";

    for(int i = 0; i < dealer_hand_.size(); i++)
    {
        dealer_hand_[i].printCard();
    }

    std::cout << "\n";
}
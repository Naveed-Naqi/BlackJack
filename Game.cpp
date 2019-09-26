#include "Game.hpp"
#include <chrono>
#include <thread>
#include <iostream>

Game::Game() : curr_top_deck_(0)
{
    dealCards();
}

void Game::delay()
{
    using namespace std::chrono;
    using namespace std::this_thread;
}

void Game::startGame()
{
   std::cout << "Welcome to Blackjack! Press 'H' to hit and 'P' to pass \n";

   bool game_over = false;
   std::string player_reponse = "";

   while(!game_over)
   {
       

        displayDealerHand();
        displayPlayerHand();

        std::cin >> player_reponse;

        if(player_reponse == "H")
        {
            player_hand_.addCard(deck_[curr_top_deck_]);
            curr_top_deck_++;

            if(player_hand_.getSum() > 21)
            {
                game_over = true;
            }
        }
        else if(player_reponse == "P")
        {
            game_over = true;
        }
   }
    
    std::cout << "Now the dealer will hit \n";

    while (dealer_hand_.getSum() < 16)
    {
        displayDealerHand();

        dealer_hand_.addCard(deck_[curr_top_deck_]);
        curr_top_deck_++;
    }

    revealDealerHand();
    displayPlayerHand();

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
        curr_top_deck_++;

        dealer_hand_.addCard(deck_[curr_top_deck_]);
        curr_top_deck_++;
    }

    if(player_hand_.containsAce()) 
    {
        player_has_ace_ = true;
    }
    else if(dealer_hand_.containsAce())
    {
        dealer_has_ace_ = true;
    }
}

void Game::displayPlayerHand()
{
    std::cout << "Your hand is as follows: ";

    for(int i = 0; i < player_hand_.size(); i++)
    {
        player_hand_[i].printCard();
    }

    std::cout << "\n";
}

void Game::displayDealerHand()
{
    std::cout << "The dealer's hand is follows: ";
    std::cout << "One facedown card and ";

    for(int i = 1; i < dealer_hand_.size(); i++)
    {
        dealer_hand_[i].printCard();
    }

    std::cout << "\n";
}

void Game::revealDealerHand()
{
    std::cout << "The dealers hand is as follows: ";

    for(int i = 0; i < dealer_hand_.size(); i++)
    {
        dealer_hand_[i].printCard();
    }

    std::cout << "\n";
}
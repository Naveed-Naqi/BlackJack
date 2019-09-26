#include "Hand.hpp"
#include "Deck.hpp"
#include "Game.hpp"


int main()
{
   bool replay = true;
   std::string player_reponse = "";

   Game Blackjack;

   while(replay)
   {
       replay = false;
       Blackjack.startGame();

       std::cout << "Enter 'R' if you would like to replay (not case sensitive)" << std::endl;

       std::cin >> player_reponse;

       if(Blackjack.changeToUpperCase(player_reponse) == "R")
       {
           replay = true;
       }
   }
}

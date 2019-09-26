#include "Hand.hpp"
#include "Deck.hpp"
#include "Game.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    using namespace std::chrono;
    std::cout << "Hello waiter\n" << std::flush;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
}

/*
int main()
{
   Game Blackjack;
   Blackjack.startGame();
}
*/
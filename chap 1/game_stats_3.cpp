//Game Stats 3
//Demonstrates Constants

#include <iostream>

int main(){
    const int ALIENS_POINT = 150;
    int aliensKilled = 10;
    int score = aliensKilled * ALIENS_POINT;
    std::cout << "score: " << score << std::endl;

    enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
    difficulty myDifficulty = EASY;
    enum ship_Cost {FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50};
    ship_Cost myShipCost = BOMBER_COST;
    std::cout << "\nTo upgrade my ship to a Cruiser will cost "
         << (CRUISER_COST - myShipCost) << " Resource point.\n";

    return 0;
}
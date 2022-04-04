//Game Stats
//Demonstrates declaring and initializing variables

#include <iostream>

int main(){
    int score;
    double distance;
    char playAgain;
    bool shieldUp;

    short lives, aliensKilled;

    score = 0;
    distance = 1200.76;
    playAgain = 'y';
    shieldUp = true;
    lives = 3;
    aliensKilled = 10;

    double engineTemp = 6572.89;
    std::cout << "\nscore: "    << score << std::endl;
    std::cout << "distance: "   << distance << std::endl;
    std::cout << "playAgain: "  << playAgain << std::endl;
    //skipping shieldUp since you don't generally print Boolean values
    std::cout << "lives: " << lives << std::endl;
    std::cout << "aliensKilled: " << aliensKilled << std::endl;
    std::cout << "engineTemp: " << engineTemp << std::endl;
    
    int fuel;
    std::cout << "\nHow much fuel?";
    std::cin >> fuel;
    std::cout << "fuel: " << fuel << std::endl;

    typedef unsigned short int ushort;
    ushort bonus = 10;
    std::cout << "\nbonus: " << bonus << std::endl;

    return 0;
}
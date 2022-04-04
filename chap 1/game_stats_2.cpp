//Game Stats 2.0
//Demonstrates arithmetic operations with varibles

#include <iostream>

int main(){
    unsigned int score = 5000;
    std::cout << "score: " << score << std::endl;

    //alternating the value of a variable
    score = score + 100;
    std::cout << "score: " << score << std::endl;

    //combine assignment operator
    score += 100;
    std::cout << "score: " << score << std::endl;

    //increment operators
    int lives = 3;
    ++lives;
    std::cout << "lives: " << lives << std::endl;

    lives = 3;
    lives++;
    std::cout << "lives: " << lives << std::endl;

    lives = 3;
    int bonus = ++lives * 10;
    std::cout << "lives, bonus: " << lives << ", " << bonus <<std::endl;

    lives = 3;
    bonus = lives++ * 10;
    std::cout << "lives, bonus: " << lives << ", " << bonus << std::endl;

    //interger wrap around
    score = 4294967295;
    std::cout << "\nscore: " << score << std::endl;
    ++score;
    std::cout << "score: " << score << std::endl;

    return 0;
}
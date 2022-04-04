//Referencing
//Demonstrates using references
#include <iostream>

int main()
{
    int myScore = 1000;
    int& mikeScore = myScore;   //create a reference

    std::cout << "myScore is: " << myScore << std::endl;
    std::cout << "mikeScore is: " << mikeScore << "\n\n";

    std::cout << "Adding 500 to myScore\n";
    myScore += 500;
    std::cout << "myScore is: " << myScore << std::endl;
    std::cout << "mikeScore is: " << mikeScore << "\n\n";

    std::cout << "Adding 500 to mikeScore.\n";
    mikeScore += 500;
    std::cout << "myScore is: " << myScore << std::endl;
    std::cout << "mikeScore is: " << mikeScore << "\n\n";

    return 0;
}
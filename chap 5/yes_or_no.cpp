//Yes or No
//Demonstrates return values and parameters

#include <iostream>
#include <string>

char askYesNo1();
char askYesNo2(std::string question);

int main()
{
    char answer1 = askYesNo1();
    std::cout << "Thanks for answering: " << answer1 << "\n\n";

    char answer2 = askYesNo2("Do you wish to save your game?");
    std::cout << "Thanks for answering: " << answer2 << std::endl;

    return 0;
}

char askYesNo1()
{
    char respond1;
    do 
    {
        std::cout << "Please enter 'y' or 'n': ";
        std::cin >> respond1;
    } while(respond1 != 'y' && respond1 != 'n');

    return respond1;
}

char askYesNo2(std::string question)
{
    char respond2;
    do
    {
        std::cout << question << " (y/n): ";
        std::cin >> respond2;
    } while(respond2 != 'y' && respond2 != 'n');

    return respond2;
}
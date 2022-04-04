//Play Again 2
//Demonstrates do loops
#include <iostream>

int main(){
    char again;
    do {
        std::cout << "\n**Play an exciting game**";
        std::cout << "\nDo you want to play again?(y/n): ";
        std::cin >> again;
    } while(again == 'y');

    std::cout << "\nOkay, bye!";

    return 0;
}
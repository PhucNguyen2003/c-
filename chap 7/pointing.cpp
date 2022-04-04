//Pointing
//Demonstrates using pointer

#include <iostream>
#include <string>

int main(){
    int* pAPointer;     //declare a pointer

    int* pScore = 0;    //declare and initialize a pointer

    int score = 1000;
    pScore = &score;    //assign pointer pScore address of variable score

    std::cout << "Assigning &score to pScore\n";
    std::cout << "&score is: " << &score << "\n";   //address of score variable
    std::cout << "pScore is: " << pScore << "\n";   //address store in pointer
    std::cout << "score is: " << score << "\n";
    std::cout << "*pScore is: " << *pScore << "\n\n";   //value pointed to by pointer

    std::cout << "Adding 500 to score\n";
    score+= 500;
    std::cout << "score is: " << score << "\n";
    std::cout << "*pScore is: " << *pScore << "\n\n";

    std::cout << "Adding 500 to *pScore\n";
    *pScore += 500;
    std::cout << "score is: " << score << "\n";
    std::cout << "*pScore is: " << *pScore << "\n\n";

    std::cout << "Assigning &newScore to pScore\n";
    int newScore = 5000;
    pScore = &newScore;
    std::cout << "&newScore is: " << &newScore << "\n";
    std::cout << "pScore is: " << pScore << "\n";
    std::cout << "newScore is: " << newScore << "\n";
    std::cout << "*pScore is: " << *pScore << "\n\n";

    std::cout << "Assigning &str to pStr\n";
    std::string str = "score";
    std::string* pStr = &str;    //pointer to string object
    std::cout << "str is: " << str << "\n";
    std::cout << "*pStr is: " << *pStr << "\n";
    std::cout << "(*pStr).size() is: "  << (*pStr).size() << "\n";
    std::cout << "pStr->size() is: " << pStr->size() << "\n";

    return 0;
}
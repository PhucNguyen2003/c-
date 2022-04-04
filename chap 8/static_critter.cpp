//Static Critter
//Demonstrate static member variables and functions

#include <iostream>

class Critter
{
public:
    static int s_Total;     //static member variable declaration
                            //total number of Critter object in existence
    Critter(int hunger = 0);
    static int GetTotal();   //static member function prototype

private:
    int m_Hunger;
};

int Critter::s_Total = 0;   //static member variable initialization

Critter::Critter(int hunger):
    m_Hunger(hunger)
{
    std::cout << "A critter has been born!" << "\n";
    ++s_Total;
}

int Critter::GetTotal()     //static member function definition
{
    return s_Total;
}

int main()
{
    std::cout << "The total number of critter is: ";
    std::cout << Critter::s_Total << "\n\n";

    Critter crit1, crit2, crit3;

    std::cout << "\nThe total number of critter is: ";
    std::cout << Critter::GetTotal() << "\n";

    return 0;
}

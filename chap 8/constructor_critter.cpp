//Constructor Critter
//Demonstrates constructor

#include <iostream>

class Critter
{
public:
    int m_Hunger;

    Critter(int m_Hunger = 0);      //constructor prototype
    void Greet();
};

Critter::Critter(int hunger)        //constructor definition
{
    std::cout <<  "A new critter has been born!" << std::endl;
    m_Hunger = hunger;
}

void Critter::Greet()
{
    std::cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n";
}

int main()
{
    Critter crit;
    crit.m_Hunger = 5;
    crit.Greet();
    
    return 0;
}
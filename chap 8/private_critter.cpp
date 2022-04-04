//Private Critter
//Demonstrates setting member access level

#include <iostream>

class Critter
{
public:             //begin public section
    Critter(int hunger = 0);
    int GetHunger() const;
    void SetHunger(int hunger);

private:            //begin private section
    int m_Hunger;
};

Critter::Critter(int hunger):
    m_Hunger(hunger)
{
    std::cout << "A new critter has been born!" << '\n';
}

int Critter::GetHunger() const
{
    return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
    if(hunger < 0)
    {
        std::cout << "You can't set a critter's hunger to a negative number.\n\n";
    }
    else 
    {
        m_Hunger = hunger;
    }
}

int main()
{
    Critter crit(5);
    //std::cout << crit.m_Hunger;   //illegal .m_Hunger is private!
    std::cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

    std::cout << "Calling SetHunger() with -1.\n";
    crit.SetHunger(-1);

    std::cout << "Calling SetHunger() with 9.\n";
    crit.SetHunger(9);
    std::cout << "Calling GetHunger: " << crit.GetHunger() << "\n\n";

    return 0;
}
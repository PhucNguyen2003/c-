/*Create a critter
While the player doesn't want to quit the game
    Present a menu of choices to the player
    If the player wants to listen to the critter
        Make the critter talk
    If the player wants to feed the critter
        Make the critter eat
    If the player wants to play with the critter
        Make the critter play
*/

//Critter Caretaker
//Stimulates  caring for a virtual pet

#include <iostream>

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void RevealCritData();
    void CritWant();
private:
    int m_Hunger;
    int m_Boredom;

    int GetMood() const;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom):
    m_Hunger(hunger),
    m_Boredom(boredom)
{}

void Critter::CritWant()
{
    if( (m_Hunger > 5) && (m_Boredom > 5) )
    {
        std::cout << "I want to eat and play!!\n";
    }
    else if( m_Hunger > 5)
    {
        std::cout << "I'm quite hungry...\n";
    } 
    else if( m_Boredom > 5)
    {
        std::cout << "Hey, let's play, I'm bored...\n";
    }
    else
    {
        std::cout << "Hello human.\n";
    }
}

void Critter::RevealCritData()
{
    std::cout << "Critter's hunger: " << m_Hunger << '\n';
    std::cout << "Critter's boredom: " << m_Boredom << "\n";

}

inline int Critter::GetMood() const
{
    return m_Hunger + m_Boredom;
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk()
{
    std::cout << "I'm a critter and I feel ";

    int mood = GetMood();
    if(mood > 15)
    {
        std::cout << "mad.\n";
    }
    else if(mood > 10)
    {
        std::cout << "frustrated.\n";
    }
    else if(mood > 5)
    {
        std::cout << "okay.\n";
    }
    else
    {
        std::cout << "happy.\n";
    }


    PassTime();
}

void Critter::Eat(int food)
{
    std::cout << "Brruppp.\n";
    m_Hunger -= food;
    if(m_Hunger < 0) 
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Critter::Play(int fun)
{
    std::cout << "Whee!\n";
    m_Boredom -= fun;
    if(m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}

int main()
{
    Critter crit;
    crit.Talk();

    char choice;
    char showCritData = 'n';
    do
    {
        std::cout << "\nCritter Caretaker.\n\n";
        std::cout << "0 - Quit\n";
        std::cout << "1 - Listen to your critter\n";
        std::cout << "2 - Feed your critter\n";
        std::cout << "3 - Play with your critter\n";
        std::cout << "Show Critter's hunger and boredom (y/n): " << showCritData << "\n\n";

        crit.CritWant();

        if(showCritData == 'y'){
            crit.RevealCritData();
        }
        
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case '0':
            std::cout << "Goodbye.\n";
            break;
        case '1':
            crit.Talk();
            break;
        case '2':
            crit.Eat();
            break;
        case '3':
            crit.Play();
            break;
        case 'y':
            showCritData = 'y';
            break;
        case 'n':
            showCritData = 'n';
            break;
        default:
            std::cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
            break;
        }
    } while(choice != '0');

    return 0;
}
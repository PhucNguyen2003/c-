//Critter Farm 
//Demonstrates object containment

#include <iostream>
#include <string>
#include <vector>

class Critter
{
private:
    std::string m_Name;
public:
    Critter(const std::string& name = "");
    std::string GetName() const;
};

Critter::Critter(const std::string& name):
    m_Name(name)
{}

inline std::string Critter::GetName() const
{
    return m_Name;
}

class Farm
{
public:
    Farm(int spaces = 1);
    void Add(const Critter& aCritter);
    void RollCall() const;

private:
    std::vector<Critter> m_Critter;
};

Farm::Farm(int spaces)
{
    m_Critter.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
    m_Critter.push_back(aCritter);
}

void Farm::RollCall() const
{
    for(std::vector<Critter>::const_iterator iter = m_Critter.begin(); iter != m_Critter.end(); iter++){
        std::cout << iter->GetName() << " here.\n";
    }
}

int main(){
    Critter crit("Poochie");
    std::cout << "My name is " << crit.GetName() << '\n';

    std::cout << "\nCreating critter farm.\n";
    Farm myFarm(3);
    std::cout << "\nAdding three critters to the farm.\n";
    myFarm.Add(Critter("Moe"));
    myFarm.Add(Critter("Laury"));
    myFarm.Add(Critter("Curly"));

    std::cout << "\nCalling roll...\n";
    myFarm.RollCall();

    return 0;
}
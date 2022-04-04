//Friend Critter
//Demonstrates friend functions and operator overloading

#include <iostream>
#include <string>

using namespace std;

class Critter{
    //make following functions friends of the Critter class
    friend void Peek(const Critter& aCritter);
    friend std::ostream& operator<<(std::ostream& os, const Critter& aCritter);

public:
    Critter(const string& name = "");

private:
    string m_Name;
};

Critter::Critter(const string& name):
    m_Name(name)
{}

void Peek(const Critter& aCritter);
std::ostream& operator<<(std::ostream& os, const Critter& aCritter);

int main(){
    Critter crit("Poochie");

    std::cout << "Calling Peek() to access crit's private data member, m_Name: \n";
    Peek(crit);

    std::cout << "\nSending crit object to cout with the '<<' operator:\n";
    std::cout << crit;

    return 0;
}

//global friend function which can access all of a Critter object's members
void Peek(const Critter& aCritter){
    std::cout << aCritter.m_Name << "\n";
}

//global friend function which can access all of a Critter object's members
//overloads the << operator so you can send a Critter object to cout
std::ostream& operator<<(std::ostream& os, const Critter& aCritter){
    os << "Critter Object - ";
    os << "m_Name: " << aCritter.m_Name;
    return os;
}
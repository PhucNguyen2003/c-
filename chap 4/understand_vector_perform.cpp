/*
    vector = dynamic array
    memory reserve != size of vector
    if memo isn't enough -> reallocate memo and(or) copy vector element
    ->poor performance

    capacity(): tell when will a vector have to realloactes
    reserve(): tell cp to reverve memo
*/
#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
void capacity_funtion_work()
{
    std::cout << "Creating a 10 element vector to hold scores.\n";
    std::vector<int> scores(10, 0); //initialize all 10 elements to 0
    std::cout << "Vector size is " << scores.size() << std::endl;
    std::cout << "Vector capacity is " << scores.capacity() << std::endl;

    std::cout << "Adding a score.\n";
    scores.push_back(0); //memory is reallocated to accomodate growth
    std::cout << "Vector size is " << scores.size() << std::endl;
    std::cout << "Vector capacity is " << scores.capacity() << std::endl;

    return;
}
void reserve_funtion_work()
{
    std::cout << "Creating a 10 element vector to hold scores.\n";
    std::vector<int> scores(10, 0); //initialize all 10 elements to 0
    std::cout << "Vector size is " << scores.size() << std::endl;
    std::cout << "Vector capacity is " << scores.capacity() << std::endl;

    std::cout << "Reserve more memory.\n";
    scores.reserve(20); //reserve memory for 10 additional elements
    std::cout << "Vector size is " << scores.size() << std::endl;
    std::cout << "Vector capacity is " << scores.capacity() << std::endl;

    return;
}
int main()
{
    reserve_funtion_work();
    
    return 0;
}

//High Scores
//Demonstrate algorithms
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main(){
    std::vector<int>::const_iterator iter;

    std::cout << "Creating a list of score.";
    std::vector<int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    std::cout << "\nHighscore:\n";
    for(iter = scores.begin(); iter != scores.end(); iter++)
    {
        std::cout <<  *iter << std::endl;
    }

    std::cout << "\nFinding a score.";
    std::cout << "\nEnter a score to find:";
    int score;
    std::cin >> score;
    iter = std::find(scores.begin(), scores.end(), score);
    if(iter != scores.end())
    {
        std::cout << "Score found.";
    }
    else
    {
        std::cout << "Score not found.\n";
    }

    std::cout << "\nRandomizing score.";
    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(scores.begin(), scores.end());
    std::cout << "\nHigh scores:\n";
    for(iter = scores.begin(); iter != scores.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << "\nSorting score.";
    std::sort(scores.begin(), scores.end());
    std::cout << "\nHigh score:\n";
    for(iter = scores.begin(); iter != scores.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
/*
    pesudocode:
        Create a group of words [check]
        Pick a random word from a the group as secret word [check]
        While player hasn't made too many incorrect guesses and hasn't guess the secret word [check]
            Tell player how many incorrect guesses he or she has left [check]
            Show the player the letters he or she has guessed [check]
            Show the player how much of the secret word he or she has guessed [check]
            Get the player's next guess [check]
            While the player has entered a letter that he or she has guessed [check]
                Get player's guess [check]
            Add the new guess to the group of used letters [check]
            If the guess is in the secret word
                Tell the player the guess is correct [check]
                Update the word guessed so far with the new letter [check]
            Otherwise
                Tell the player the word is incorrect [check]
                Increasement the number of incorrect guesses the player had made [check]
        If the player has made too many incorrect guess
            Tell the player that he or she may has been hanged [check]
        Otherwise
            Congratulate the player on guessing the correct word [check]
*/

//Hang Man
//The classic game of hang man

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

int main(){
    //Set up
    const int MAX_WRONG = 8; // maximum number of incorrect guess allowed

    std::vector<std::string> words; //collection of possible words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(words.begin(), words.end());
    const std::string THE_WORD = words[0];      //word to guess
    int wrong = 0;                              //number of incorrect guesses
    std::string soFar(THE_WORD.size(), '-');    //word guessed so far
    std::string used = "";                      //letters already guessed

    std::cout << "Welcome to Hangman. Good luck!\n";
    
    //main loop
    while((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        std::cout << "\n\nYou have " << (MAX_WRONG - wrong);
        std::cout << " incorrect guesses left.\n";
        std::cout << "\nYou have used the following letters:\n" << used << std::endl;
        std::cout << "So far, the word is:\n" << soFar << std::endl;

        char guess;
        std::cout << "\n\nEnter your guess: ";
        std::cin >> guess;
        guess = toupper(guess); //make uppercase since secret word is uppercase
        while(used.find(guess) != std::string::npos)
        {
            std::cout << "\nYou have already guessed " << guess << std::endl;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if(THE_WORD.find(guess) != std::string::npos)
        {
            std::cout << "That's right! " << guess << " is in the word.\n";

            //update soFar to include newly guessed letter
            for(int i = 0; i < THE_WORD.length(); i++)
            {
                if(THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            std::cout << "Sorry, " << guess << " isn't in the word.\n";
            wrong++;
        }
    }

    //shut down
    if(wrong == MAX_WRONG)
    {
        std::cout << "\nYou've been hanged!";
    }
    else
    {
        std::cout << "\nThe word was " << THE_WORD << std::endl;
    }
    
    return 0;
}
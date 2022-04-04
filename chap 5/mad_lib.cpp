//Mad Lib
//Create a story based on user input
#include <iostream>
#include <string>

std::string askText(std::string prompt);
int askNumber(std::string prompt);
void tellStory(std::string name, std::string noun, int number, std::string bodyPart, std::string verb);

int main(){
    std::cout << "Welcome to Mad Lib.\n\n";
    std::cout << "Answer the following question to help create a new story.\n";

    std::string name = askText("Please enter a name: ");
    std::string noun = askText("Please enter a noun: ");
    int number = askNumber("Please enter a number: ");
    std::string bodyPart = askText("Please enter a body part: ");
    std::string verb = askText("Please enter a verb: ");

    tellStory(name, noun, number, bodyPart, verb);

    return 0;
}

std::string askText(std::string prompt)
{
    std::string text;
    std::cout << prompt;
    std::cin >> text;
    return text;
}

int askNumber(std::string prompt)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    return num;
}

void tellStory(std::string name, std::string noun, int number, std::string bodyPart, std::string verb)
{
    std::cout << "\nHere's your story:\n";
    std::cout << "The famous explorer ";
    std::cout << name;
    std::cout << " had nearly given up a life-long quest to find\n";
    std::cout << "The Lost City of ";
    std::cout << noun;
    std::cout << " when one day, the ";
    std::cout << noun;
    std::cout << " found by the explorer.\n";
    std::cout << "Surrounded by ";
    std::cout << number;
    std::cout << " " << noun;
    std::cout << ", a tear came to ";
    std::cout << name << "'s ";
    std::cout << "after all this time, the quest was finally over. ";
    std::cout << "And then, the ";
    std::cout << noun << std::endl;
    std::cout << "promptly devoured ";
    std::cout << name << ". ";
    std::cout << "The moral of the story? Be careful what you ";
    std::cout << verb;
    std::cout << " for.";
}
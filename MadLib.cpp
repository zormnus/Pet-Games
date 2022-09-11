#include <iostream>

namespace madLib {
    std::string askText(std::string prompt) {
        std::string text;
        std::cout << prompt;
        std::cin >> text;
        return text;
    }

    int askNumber(std::string prompt) {
        int number;
        std::cout << prompt;
        std::cin >> number;
        return number;
    }

    void tellStory(std::string name, std::string noun, int number, std::string bodyPart, std::string verb) {
        using std::cout;
        cout << "\nHere's your story:\n";
        cout << "The famous explorer ";
        cout << name;

        cout << " had nearby given up a life-long quest to find\n";
        cout << "The Lost City of ";
        cout << noun;

        cout << " when one day, the ";
        cout << noun;
        cout << " found the explorer";
        cout << " Surrounded by ";
        cout << number;

        cout << " " << noun << ". a tear came to ";
        cout << name << "'s ";
        cout << bodyPart << ".\n";

        cout << "After all this time, the quest was finally over. ";
        cout << "And then, the ";
        cout << noun << "\n";
        cout << "promptly devoured ";
        cout << name << ". ";

        cout << "The moral of the story? Be careful what you ";
        cout << verb << " for.";
    }

}

int main() {
    std::cout << "Welcome to Mad Lib.\n\n";
    std::cout << "Answer the following questions to help create a new story\n";
    auto name = madLib::askText("Enter your name: ");
    auto noun = madLib::askText("Enter a plural noun: ");

    auto number = madLib::askNumber("Enter your number: ");
    auto bodypart = madLib::askText("Enter a body part: ");
    auto verb = madLib::askText("Enter a verb: ");

    madLib::tellStory(name, noun, number, bodypart, verb);
    return 0;
}
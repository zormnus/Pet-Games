#include <iostream>
#include <unordered_map>
#include <ctime>

using std::cout;
using std::cin;

namespace wordJumble {
    void startGame() {
        static std::string fields[] {"wall", "glasses", "labored", "persistent", "jumble"};
        static const int fields_size = 5;
        static std::unordered_map<std::string, std::string> words {
                {"wall", "Do you feel you're banging your head against something?"},
                {"glasses", "These might help you see the answer."},
                {"labored", "Going slowly. is it?"},
                {"persistent", "Кеер at it."},
                {"jumble", "It's what the game is all about."}
        };


        int random_index = rand() % fields_size;
        auto word = fields[random_index];
        auto word_cpy = word;
        auto hint = words[word];
        auto length = word.size();

        for (int i = 0; i < length; ++i) {
            int index1 = rand() % length;
            int index2 = rand() % length;
            std::swap(word[index1], word[index2]);
        }

        cout << "The jumble is: " << word;
        std::string guess;

        while ((guess != "quit") && (guess != word_cpy)) {
            cout << "\n\nYour guess: ";
            cin >> guess;
            if (guess == word_cpy) {
                cout << "\nThat's it! You guessed it!\n";
                cout << "Thanks for a game!\n";
            }
            else {
                cout << "Try again.\n";
            }
        }
    }
}

int main() {
    srand(time(nullptr));

    cout << "\t\t\tWelcome to Word Jumble\n\n";
    cout << "Unscram the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";

    while (true) {
        wordJumble::startGame();
        cout << "Do you want to play again? (y/n)\n";
        char result;
        cin >> result;
        if (result == 'n')
            break;
    }

    return 0;
}
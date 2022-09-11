#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

namespace hangman{
    const int MAX_WRONG = 8;

    void startGame() {
        static std::vector<std::string> words {"GUESS", "HANGMAN", "DIFFICULT"};
        std::random_shuffle(words.begin(), words.end());
        auto word = words[1];
        std::string result(word.size(), '-');
        int incorrect_guesses = 0;
        std::vector<char> used_letters;

        while ((MAX_WRONG - incorrect_guesses != 0) && (result != word)) {
            std::cout << "You have " << MAX_WRONG - incorrect_guesses << " incorrect guesses left\n";
            std::cout << "You've used the following letters: ";
            if (!used_letters.empty())
                std::for_each(used_letters.begin(), used_letters.end(), [](const char& symbol){
                    std::cout << symbol << ' ';
                });
            std::cout << std::endl;

            std::cout << "So far, the word is: " << result << '\n';

            std::cout << "Enter your guess:";
            char guess;
            std::cin >> guess;
            guess = toupper(guess);
            used_letters.push_back(guess);

            int index = 0;
            std::vector<int> indexes;
            while ((index = word.find(guess,index)) != std::string::npos) {
                indexes.push_back(index);
                index += 1;
            }

            for (const auto& item : indexes) {
                result[item] = guess;
            }

            if (indexes.empty()){
                std::cout << "Incorrect guess!\n\n\n";
                incorrect_guesses++;
            }
            else {
                std::cout << "Correct!\n\n\n";
            }


        }
        if (MAX_WRONG - incorrect_guesses == 0) {
            std::cout << "Game over! You lose :(\n";
        }
        else {
            std::cout << "Congratulations! You win!\n";
        }
        std::cout << "The word is: " << word << std::endl;
    }

}

int main() {
    srand(time(nullptr));
    std::cout << "Welcome to Hangman. Good luck!" << std::endl;

    while (true) {
        hangman::startGame();
        std::cout << "Do you want to play again? (y/n)\n";
        char s;
        std::cin >> s;
        s = tolower(s);
        if (s == 'n')
            break;
    }

    return 0;

}
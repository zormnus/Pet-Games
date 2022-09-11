#include <iostream>
#include <time.h>

void startGame() {
    srand(static_cast<unsigned int>(time(nullptr)));

    using std::cout;
    using std::cin;
    using std::endl;

    int attempts = 0;
    auto number = rand() % 100;
    while (true) {
        int guess;
        cout << "Enter a guess: ";
        cin >> guess;
        attempts++;

        if (number == guess) {
            cout << "That's it! You got it in " << attempts << " attempts!" << endl;
            cout << "Do you want to keep playing? (y/n) ";
            char result;
            cin >> result;
            if (result == 'y') {
                number = rand() % 100;
                attempts = 0;
                continue;
            }
            else if (result == 'n')
                break;
        }
        else if (guess < number)
            cout << "Too low!" << std::endl;
        else
            cout << "Too high!" << std::endl;
    }
}

int main() {
    startGame();
    return 0;
}
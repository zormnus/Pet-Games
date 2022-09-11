#include <iostream>

void startGame() {
    const int GOLD_PIECES = 900;
    using std::cout;
    using std::cin;
    using std::string;
    cout << "Welcome to Lost Fortune!" << std::endl << std::endl;
    cout << "Please enter the following for your personalized adventure" << std::endl;
    unsigned int adventurers;
    cout << "Enter a number: ";
    cin >> adventurers;
    unsigned int killed;
    cout << "Enter a number, smaller than the first: ";
    cin >> killed;
    auto survivors = adventurers - killed;
    string leader;
    cout << "Enter your last name: ";
    cin >> leader;

    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary rogue: " << leader << ". \n";
    cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of " << leader;
    cout << ". and the ogres were defeated. but at a cost. ";
    cout << "Of the adventurers. " << killed << " were vanqui shed. ";
    cout << "leaving just "<< survivors << " in the group.\n";
    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest. ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split "<< GOLD_PIECES << " gold pieces.";
    cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course.\n";
}

int main() {
    startGame();
    return 0;
}
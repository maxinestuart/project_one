/*
 * Author: Maxine Stuart
 * Name: Project 1 - clock
 * Purpose: 12 and 24 hr clock simulator for Chada Tech interview 
 */

#include <iostream>
#include <string>
using namespace std;

unsigned int getMenuChoice(unsigned int maxChoice) {
    int menuChoice;

    cin >> menuChoice;

    return 0;
}

std::string twoDigitString(unsigned int n) { // returns numbers as 2-digit strings
    std::string result;

    if ((n >= 0) && (n <= 9)) { // add a 0 to single-digits and output as a string
        result = "0" + std::to_string(n);
    }
    else {
        result = std::to_string(n);
    }

    return result;
}

void mainMenu() {

    getMenuChoice(4);

    return;
}

int main() {
    cout << twoDigitString(33) << endl; // FIXME: test output

    return 0;
}
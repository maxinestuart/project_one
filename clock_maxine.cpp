/*
 * Author: Maxine Stuart
 * Name: Project 1 - clock
 * Purpose: 12 and 24 hr clock simulator for Chada Tech interview 
 */

#include <iostream>
#include <string>
using namespace std;

unsigned int getMenuChoice(unsigned int maxChoice) { // FIXME: handles correct menu choices
    int menuChoice;

    cin >> menuChoice;

    return 0;
}

string nCharString(size_t n, char c) { // FIXME: Returns a string of length n, each character a c.

    return "*"; 
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

string formatTime24(unsigned int h, unsigned int m, unsigned int s) { // FIXME: return time as hh:mm:ss

    return "hh:mm:ss";
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) { // FIXME: return time as hh:mm:ss

    return "12:00:00 A M";
}

void printMenu(char * strings[], unsigned int numStrings, unsigned char width) { // FIXME: print formatted menu

    return;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) { // FIXME: print clocks

    return;
}

void addOneSecond() { // FIXME: add 1 second

    return;
}

void addOneMinute() { // FIXME: add 1 minute

    return;
}

void addOneHour() { // FIXME: add 1 hour

    return;
}

void mainMenu() { // FIXME: repeats getting the user's choice and taking the appropriate action until the user chooses 4 for exit

    getMenuChoice(4);

    return;
}

int main() {
    cout << twoDigitString(33) << endl; // FIXME: test output

    return 0;
}
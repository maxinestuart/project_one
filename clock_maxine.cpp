/*
 * Author: Maxine Stuart
 * Name: Project 1 - clock
 * Purpose: 12 and 24 hr clock simulator for Chada Tech interview 
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

void clockSetup() { // print welcome and set initial time from input
    int hour = 0;
    int minute = 0;
    int second = 0;

    // validate inputs for hour, minute, and second
    cout << "Welcome! Please enter the time for initial clock setup." << endl;
    cout << "Enter hour:" << endl; 
    while (!(cin >> hour) || hour < 0 || hour > 24) {
        cout << "Please enter a valid integer between 0 and 24:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter minute:" << endl; 
    while (!(cin >> minute) || minute < 0 || minute > 59) {
        cout << "Please enter a valid integer between 0 and 59:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter second:" << endl; 
    while (!(cin >> second) || second < 0 || second > 59) {
        cout << "Please enter a valid integer between 0 and 59:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << hour << minute << second; // FIXME: return/output what? 
}

unsigned int getMenuChoice(unsigned int maxChoice) { // FIXME: handles correct menu choices
    int menuChoice;

    cin >> menuChoice;

    return 0;
}

string nCharString(size_t n, char c) { // Returns a string of length n, each character a c.
    string widthStars;
    
    widthStars.append(n, c);

    return widthStars; 
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

string formatTime24(unsigned int h, unsigned int m, unsigned int s) { // return 24 hour time as hh:mm:ss
    string time24Hr;

    time24Hr = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

    return time24Hr;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) { // return 12 hour time as hh:mm:ss AM / PM
    string time12Hr;
    int hour = h;
    string period = " A M";

    if (h > 12) {
        hour = (h % 12);
        period = " P M";
    }
    
    time12Hr = twoDigitString(hour) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + period;

    return time12Hr;
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

int main() { // FIXME: main logic
    clockSetup();

    cout << twoDigitString(33) << endl; // FIXME: test output

    return 0;
}
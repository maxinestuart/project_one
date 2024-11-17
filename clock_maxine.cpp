/*
 * Author: Maxine Stuart
 * Name: Project 1 - clock
 * Purpose: 12 and 24 hr clock simulator for Chada Tech interview 
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;


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
    unsigned int hour = h;
    string period = " A M";

    if (h == 0) {
        hour = 12; // 12 am
    }
    else if (h >= 12) {
        period = " P M";
        if (h > 12) {
            hour = h - 12;
        }
    }
    
    time12Hr = twoDigitString(hour) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + period;

    return time12Hr;
}

void clockSetup(unsigned int &h, unsigned int &m, unsigned int &s) { // print welcome and set initial time from input

    // validate inputs for hour, minute, and second
    cout << "Welcome! Please enter the time for initial clock setup." << endl;
    cout << "Enter hour:" << endl; 
    while (!(cin >> h) || h < 0 || h > 24) {
        cout << "Please enter a valid integer between 0 and 24:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter minute:" << endl; 
    while (!(cin >> m) || m < 0 || m > 59) {
        cout << "Please enter a valid integer between 0 and 59:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter second:" << endl; 
    while (!(cin >> s) || s < 0 || s > 59) {
        cout << "Please enter a valid integer between 0 and 59:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << endl;
}

const char** getMenuItems(unsigned int &numStrings) {
    static const char *menuItems[] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
    numStrings = 4;
    return menuItems;
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

void printMenu(const char * strings[], unsigned int numStrings, unsigned char width) { // FIXME: print formatted menu
    cout << nCharString(width, '*') << endl;
    for (unsigned int i = 0; i < numStrings; ++i) {
        cout << "* " << i + 1 << " - " << strings[i];

        size_t itemLength = 2 + to_string(i).length() + 3 + string(strings[i]).length(); // length of line content
        size_t spaceCount = (width > itemLength) ? (width - itemLength - 1) : 0; // counts spaces needed 
        cout << nCharString(spaceCount, ' ');
        cout << "*" << endl;
        if ((i + 1) < numStrings) { // empty lines except after last menu item
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;

    return;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) { // print both formatted clocks
    string time12 = formatTime12(h, m, s);
    string time24 = formatTime24(h, m, s);

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << '*' << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << '*' << nCharString(3, ' ');
    cout << '*' << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << '*' << endl;
    cout << endl;
    cout << '*' << nCharString(6, ' ') << time12 << nCharString(7, ' ') << '*' << nCharString(3, ' ');
    cout << '*' << nCharString(8, ' ') << time24 << nCharString(9, ' ') << '*' << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
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
    unsigned int h = 0, m = 0, s = 0;
    unsigned int numStrings;
    const char **menuItems = getMenuItems(numStrings);

    clockSetup(h, m, s);
    displayClocks(h, m, s);
    printMenu(menuItems, numStrings, 27);

    return 0;
}
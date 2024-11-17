/*
 * Author: Maxine Stuart
 * Name: Project 1 - clock
 * Purpose: 12 and 24 hr clock simulator for Chada Tech interview 
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;
unsigned int second;
unsigned int minute;
unsigned int hour;


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

    // validate user inputs for hour, minute, and second
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

// second getter + setter
void setSecond(unsigned int s) {
    second = s;
}

unsigned int getSecond() {
    return second;
}

// minute getter + setter
void setMinute(unsigned int m) {
    minute = m;
}

unsigned int getMinute() {
    return minute;
}

// hour getter + setter
void setHour(unsigned int h) {
    hour = h;
}

unsigned int getHour() {
    return hour;
}

const char** getMenuItems(unsigned int &numStrings) { // constant menu items
    static const char *menuItems[] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
    numStrings = 4;
    return menuItems;
}

unsigned int getMenuChoice(unsigned int maxChoice) { // handles correct menu choices
    unsigned int menuChoice;

    // loop for input until in range 1-max
    while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > maxChoice) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return menuChoice;
}

string nCharString(size_t n, char c) { // Returns a string of length n, each character a c.
    string widthStars;
    
    widthStars.append(n, c);

    return widthStars; 
}

void printMenu(const char * strings[], unsigned int numStrings, unsigned char width) { // print formatted menu options
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

void addOneHour() { // FIXME: add 1 hour
    if ((getHour() >= 0) && (getHour() <= 22)) {
        setHour(getHour() + 1);
    }
    else if (getHour() == 23) {
        setHour(0);
    }
    return;
}

void addOneMinute() { // FIXME: add 1 minute
    if ((getMinute() >= 0) && (getMinute() <= 58)) {
        setMinute(getMinute() + 1);
    }
    else if (getMinute() == 59) {
        setMinute(0);
        addOneHour();
    }
    return;
}

void addOneSecond() { // FIXME: add 1 second
    if ((getSecond() >= 0) && (getSecond() <= 58)) {
        setSecond(getSecond() + 1);
    }
    else if (getSecond() == 59) {
        setSecond(0);
        addOneMinute();
    }
    return;
}

void mainMenu(unsigned int &h, unsigned int &m, unsigned int &s) { // repeats getting the user's menu choice and taking the appropriate action until the user chooses 4 for exit
    unsigned int choice = 0;
    unsigned int numStrings;
    const char **menuItems = getMenuItems(numStrings);

    while (choice != 4) {
        printMenu(menuItems, numStrings, 27);
        choice = getMenuChoice(4); // pull input 

        switch (choice) { // switch cases handle menu choices
            case 1: addOneHour();
            displayClocks(h, m, s);
            break;
            case 2: addOneMinute();
            displayClocks(h, m, s);
            break;
            case 3: addOneSecond();
            displayClocks(h, m, s);
            break;
            case 4: cout << "Exited." << endl;
            break;
            default: cout << "Please select one of the choices shown." << endl;
        }
    }
}

int main() { // FIXME: main logic
    unsigned int h = 0, m = 0, s = 0;
    unsigned int numStrings;
    const char **menuItems = getMenuItems(numStrings);

    clockSetup(h, m, s);
    displayClocks(h, m, s);
    mainMenu(h, m, s);

    return 0;
}
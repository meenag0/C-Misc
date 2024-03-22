#include <iostream>
using namespace std;

void convertTemp(char unit, float temp);

void convertTemp(char unit, float temp) {
    cout << "Please enter your temperature: ";
    cin >> temp;

    cout << "Please enter the units (F/C): ";
    cin >> unit;

    float resultTemp;
    if (unit == 'F' || unit == 'f') {
        resultTemp = (temp - 32) * 5 / 9;
        cout << "A temperature of " << temp << " degrees Fahrenheit is equivalent to " << resultTemp << " degrees Celsius.\n";
    } else if (unit == 'C' || unit == 'c') {
        resultTemp = (temp * 9 / 5) + 32;
        cout << "A temperature of " << temp << " degrees Celsius is equivalent to " << resultTemp << " degrees Fahrenheit.\n";
    } else {
        cout << "Please enter a valid input.\n";
        convertTemp(unit, temp); // Recursive call only when input is invalid
        return;
    }

    char YorN;
    cout << "Do you want another conversion (Y/N)? ";
    cin >> YorN;

    if (YorN == 'Y' || YorN == 'y') {
        convertTemp(' ', 0);
    } else {
        cout << "Thank you for playing.";
    }
}

int main() {
    convertTemp(' ', 0);
    return 0;
}

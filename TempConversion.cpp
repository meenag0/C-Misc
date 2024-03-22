#include <iostream>
using namespace std;
#include <ctype.h>

void YesorNo(char YorN);
void convertTemp(char unit, float temp);

void YesorNo(char YorN){
        if (YorN == 'Y' || YorN == 'y'){
            convertTemp(' ', 0);        
        } else if (YorN == 'N' || YorN == 'n'){
            cout << "Thank you for playing.";
        } else{
            cout << "Please enter a valid input.";
            cout << "Do you want another conversion?";
            cin >> YorN;
            YesorNo(YorN);
        }
}

void convertTemp(char unit, float temp){
        cout << "Please enter your temperature: ";
        cin >> temp;

        cout << "Please enter the units (F/C): ";
        cin >> unit;

        float resultTemp;
        if (unit == 'F' || unit == 'f') {            
            resultTemp = (temp - 32 ) * 5 / 9;
        } else if (unit == 'C' || unit == 'c') {
            resultTemp = (temp  * 9 / 5) + 32;
        } else{
            cout << "Please enter a valid input.\n";
            convertTemp(' ', 0);
            return;
        }

        char YorN;
        cout << "A temperature of " << temp <<  " degrees Celsius is equivalent to " << resultTemp << " degrees Fahrenheit.\n";
        cout << "Do you want another conversion (Y/N)? ";
        cin >> YorN;

        if (YorN == 'Y' || YorN == 'y'){
            convertTemp(' ', 0);
        } else{
            cout << "Thank you for playing.";
        }
}

int main(){

    convertTemp(' ', 0);


    return 0;

}
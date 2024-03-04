#include <iostream>
using namespace std;

int main(){

    string x;

    while(x != "x"){

        cout << "C++ Help Menu \nSelect Help on:\n1. If\n2. Switch\n3. For\n4. While\n5. Do-while\nx. Exit\n"  ;

        cout << "Selection: ";
        cin >> x;

        if(x == "1"){
            cout << "If: \n\n";
        } else if(x == "2"){
            cout << "Switch: \n\n";
        } else if(x == "3"){
            cout << "For: \n\n";
        } else if(x == "4"){
            cout << "While: \n\n";
        } else if(x == "5"){
            cout << "Do-while: \n\n";
        }
    }
    cout << "Thank you. Good bye.";
}

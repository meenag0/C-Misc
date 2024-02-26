#include <iostream>
using namespace std;
#include <iomanip>



// function to convert celcius to float
double CtoF(double i){
    double CtoFResult = ((i * 9) / 5) + 32;
    return CtoFResult;
}

double FtoC(double i){
    double FtoCResult = (i - 32 ) * 5 / 9;
    return FtoCResult;
}

int main(){

    std::cout << std::fixed << std::setprecision(3);


    double i{-40};
    while(i < 101){
        cout << std::setw(9) << i << std::setw(9) << FtoC(i) <<  "  |" << std::setw(9) << i << CtoF(i) << endl;
        i+5;
    }
}
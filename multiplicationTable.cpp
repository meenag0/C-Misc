
#include <iostream>
using namespace std;



// Multiplication Table

int digs(int product){
    int j{0};
    while(product != 0){
        product = product/10;
        j++;
    }
    return j;
}

void mult(int n) {
    int i{1};
    while(i < 13){
        
        int product = n*i;
        if (digs(product) == 3){
            cout << " " << product << " |";
        } else if (digs(product) == 2){
        cout << "  " << product << " |";
        } else {
            cout << "   " << product << " |" ;
        }
        i++;
    }
    cout << endl ;

}

int main(){

    int n{0};
    while (n<13){
        if (n==0){
            cout << "  " << "  |";
            mult(1);
            // cout << endl;
        } else{
         if (digs(n) == 2){
        cout << " " << n << " |";
        } else {
            cout << "  " << n << " |" ;
        }        
        mult(n);
        }

        n++;
    }

    return 0;
}
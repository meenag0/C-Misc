#include <iostream>
using namespace std;

int main() {

  for (int i{1}; i < 10000; i++) {
    bool checkPrime = true;
    for (int j{2}; j < i; j++) {
      if (i % j == 0) {
        checkPrime = false;
        break;
      }
    }
    if (checkPrime == true) {
      cout << i << ", ";
    }
  }
}


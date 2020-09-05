#include <iostream>

using namespace std;

int main() {
    int n;
    bool isPrime = true;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0){
            isPrime = false;
            break;
        }
    }
    if (isPrime == true)
        cout << "prime" << '\n';
    else 
        cout << "composite" << '\n';   
    return 0;
}
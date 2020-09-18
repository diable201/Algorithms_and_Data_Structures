#include <iostream>

int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(long long int a, long long int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    long long int a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << '\n';
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;

int main() {
    bool isBotva = false;
    long long int n = 0;
    deque<int> first_player;
    deque<int> second_player;
    for (int i = 0; i < 5; i++) {
        int k;
        cin >> k;
        first_player.push_back(k);
    }
    for (int i = 0; i < 5; i++) {
        int k;
        cin >> k;
        second_player.push_back(k);
    }
    while (first_player.size() != 0 && second_player.size() != 0) {
        n++;
        int a = first_player.front();
        first_player.pop_front();

        int b = second_player.front();
        second_player.pop_front();

        if ((a > b && a != 9) || (a == 9 && b != 0) || (a == 0 && b == 9)) {
        first_player.push_back(a);
        first_player.push_back(b);
        } else {
        second_player.push_back(a);
        second_player.push_back(b);
        }
        if (n == 1000000) {
        cout << "botva\n" ;
        isBotva = true;
        break;
        }
    }
    if (!isBotva) {
        if (!first_player.empty())
            cout << "first " << n << '\n';
        else
            cout << "second " << n << '\n';
    }
    return 0;
}  
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> first, second;
    int n;
    cin >> n;
    while (n--) {
        char c;
        int i;
        cin >> c;
        if (c == '+') {
            cin >> i;
            second.push_back(i);
        }
        else if (c == '*') {
            cin >> i;
            second.push_front(i);
        }
        else if (c == '-') {
            cout << first.front() << '\n';
            first.pop_front();
        }
        if (second.size() > first.size()) {
            first.push_back(second.front());
            second.pop_front();
        }
    }
    return 0;
}
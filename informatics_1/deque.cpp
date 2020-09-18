#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> d;
    string command;
    while (cin >> command) {
        if (command == "push_back") {
            uint64_t x;
            cin >> x;
            d.push_back(x);
            cout << "ok" << '\n';
        }
        if (command == "push_front") {
            uint64_t x;
            cin >> x;
            d.push_front(x);
            cout << "ok" << '\n';
        }
        else if (command == "pop_front") {
            if (d.size() == 0)
               cout << "error" << '\n';     
            else {
               cout << d.front() << '\n'; 
               d.pop_front();
            }
        }
        else if (command == "pop_back") {
            if (d.size() == 0)
                cout << "error" << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if (command == "front")
            if (d.size() == 0)
                cout << "error" << '\n';
            else
                cout << d.front() << '\n';
        else if (command == "back")
            if (d.size() == 0)
                cout << "error" << '\n';
            else
                cout << d.back() << '\n';
        else if (command == "size")
            cout << d.size() << '\n';
        else if (command == "clear") {
            d.clear();
            cout << "ok" << '\n';
        }
        else if (command == "exit") {
            cout << "bye" << "\n";
            break;
        }
    }
    return 0;
}
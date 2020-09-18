#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    string command;
    while (cin >> command) {
        if (command == "push") {
            uint64_t x;
            cin >> x;
            q.push(x);
            cout << "ok" << '\n';
        }
        else if (command == "pop") {
            if (q.size() == 0)
               cout << "error" << '\n';     
            else {
               cout << q.front() << '\n'; 
               q.pop();
            }
        }
        else if (command == "front")
            if (q.size() == 0)
                cout << "error" << '\n';
            else
                cout << q.front() << '\n';
        else if (command == "size")
            cout << q.size() << '\n';
        else if (command == "clear") {
            while (!q.empty()) 
                q.pop();
            cout << "ok" << '\n';
        }
        else if (command == "exit") {
            cout << "bye" << "\n";
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    string command;
    while (cin >> command) {
        if (command == "push") {
            uint64_t x;
            cin >> x;
            st.push(x);
            cout << "ok" << '\n';
        }
        else if (command == "pop") {
            if (st.size() == 0)
               cout << "error" << '\n';     
            else { 
            cout << st.top() << '\n';
            st.pop();
            }
        }
        else if (command == "back") {
            if (st.size() == 0)
               cout << "error" << '\n';
            else
               cout << st.top() << '\n';
        }
        else if (command == "size") {
            cout << st.size() << '\n';
        }
        else if (command == "clear") {
            while (!st.empty()) 
                st.pop();
            cout << "ok" << '\n';
        }
        else if (command == "exit") {
            cout << "bye" << "\n";
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <cctype>
#include <stack>

using namespace std; 

int main() {
    string s;    
    stack <int> st;  
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (s[i] == '+')
            st.push(a + b);
        else if (s[i] == '-')
            st.push(b - a);
        else if (s[i] == '*')
            st.push(a * b);
        }
        else if (isdigit(s[i]))
            st.push(s[i] - '0');
    }
    cout << st.top() << '\n';
    return 0;
}
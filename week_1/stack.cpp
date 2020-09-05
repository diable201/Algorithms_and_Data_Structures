#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(15);
    st.push(1);

    cout << st.top() << '\n';
    st.pop();
    st.pop();
    cout << st.top() << '\n';
    cout << st.size() << '\n';
    cout << st.empty() << '\n';

    return 0;
}
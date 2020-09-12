#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << '\n';
    q.pop();
    cout << q.front() << '\n';
    cout << q.size() << '\n';
    cout << q.empty() << '\n';
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int main() {
    deque<int> q;
    q.push_back(10);
    q.push_back(20);
    q.push_front(30);
    q.push_front(40);
    cout << q.front() << '\n';
    cout << q.back() << '\n';
    return 0;
}
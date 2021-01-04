#include <iostream>
#include <stack>
#include <vector>
  
using namespace std;
 
int main() {
    int n;
    cin >> n;
    stack<int> st[500 + 1];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            st[i].push(x);
        }
    }
    vector<pair<int, int> > answer;
    if (n == 2) {
        while (!st[1].empty() && st[1].top() == 2) {
            st[2].push(st[1].top()), st[1].pop();
            answer.push_back(make_pair(1, 2));
        }
        while (!st[2].empty() && st[2].top() == 1) {
            st[1].push(st[2].top()), st[2].pop();
            answer.push_back(make_pair(2, 1));
        }
        while (!st[1].empty() && st[1].top() == 1) st[1].pop();
        while (!st[2].empty() && st[2].top() == 2) st[2].pop();
        if (!st[1].empty() || !st[2].empty()){
            cout << 0 << '\n';
            return 0;
        }
    }   
    else if (n > 2) {
        while (!st[1].empty()) {
            answer.push_back(make_pair(1, 2));
            st[2].push(st[1].top());
            st[1].pop();
        }
        for (int i = 2; i <= n; ++i) {
            while (!st[i].empty()) {
                if (st[i].top() == 1) {
                    st[1].push(1);
                    answer.push_back(make_pair(i, 1));
                }
                else {
                    if (i == 2) {
                        st[3].push(st[i].top());
                        answer.push_back(make_pair(2, 3));
                    }
                    else {
                        st[2].push(st[i].top());
                        answer.push_back(make_pair(i, 2));
                    }
                }
                st[i].pop();
            }
        }
        while (!st[2].empty()) {
            answer.push_back(make_pair(2, 1));
            st[1].push(st[2].top());
            st[2].pop();
        }
        while (!st[1].empty() && st[1].top() != 1) {
            st[st[1].top()].push(st[1].top());
            answer.push_back(make_pair(1, st[1].top()));
            st[1].pop();
        }
    }
    for (size_t i = 0; i < answer.size(); i++)
        cout << answer[i].first << " " << answer[i].second << '\n';
    return 0;
}
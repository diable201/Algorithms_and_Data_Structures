#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


string start, finish;
const int num_of_ops = 4;
unordered_map<string, int> dist;
unordered_map<string, string> previous;
unordered_set<string> visited;

string c_plus(string num) {
    if (num[0] == '9') 
        return num;
    num[0] += 1;
    return num;
}

string c_minus(string num) {
    if (num[3] == '1') 
        return num;
    num[3] -= 1;
    return num;
}

string c_left_shift(string num) {
    // 1234 = 2341
    return num.substr(1, 3) + num.substr(0, 1); 
}

string c_right_shift(string num) {
    // 1234 = 4123
    return num.substr(3, 1) + num.substr(0, 3);
}

void solution() {
    queue<string> q;
    visited.insert(start);
    dist[start] = 0;
    q.push(start);
    previous[start] = "";
    while (!q.empty()) {
        string num = q.front(); q.pop();
        if (num == finish)
                break;
        string new_num;

        for (int operation = 0; operation < num_of_ops; operation++) {
            switch (operation) {
                case 0: new_num = c_plus(num);
                        break;
                case 1: new_num = c_minus(num);
                        break;
                case 2: new_num = c_right_shift(num);
                        break;
                case 3: new_num = c_left_shift(num);
                        break;
            }

            if (!visited.count(new_num)) {
                visited.insert(new_num);
                q.push(new_num);
                previous[new_num] = num;
                dist[new_num] = dist[num] + 1;
            }
        }
    }
    vector<string> path;
    while (finish != "") {
        path.push_back(finish);
        finish = previous[finish];
    }
    reverse(path.begin(), path.end());
    for (const auto & str : path) 
        cout << str << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> start >> finish;
    solution();
    return 0;
}
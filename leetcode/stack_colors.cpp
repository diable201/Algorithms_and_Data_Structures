#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n; cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		while (!s.empty() and s.top() <= x) {
			s.pop();
		}
		s.push(x);
	}
	cout << s.size() << endl;
	return 0;
}
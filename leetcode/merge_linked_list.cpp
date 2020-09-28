#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int i = 0, j = 0;
	vector<int> c(n + m);
	while (i != n and j != m) {
		if (a[i] < b[j]) {
			c[i + j] = a[i++];
		} else {
			c[i + j] = b[j++];
		}
	}
	while (i != n) {
		c[i + j] = a[i++];
	}
	while (j != m) {
		c[i + j] = b[j++];
	}
	for (int i = 0; i < n + m; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}
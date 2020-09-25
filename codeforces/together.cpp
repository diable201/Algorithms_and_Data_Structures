#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
	int n; cin >> n;
	vector<double> x(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	} 
	double L = 0.0, R = 1.0 * 1e12;
	double eps = 1e-6;
	while (R - L > eps) {
		double mid = (L + R) / 2;
		double l = -1.0 * 1e18, r = 1.0 * 1e18;
		for (int i = 0; i < n; i++) {
			double left = x[i] - mid * v[i];
			double right = x[i] + mid * v[i];
			l = max(l, left);
			r = min(r, right);
		}
		if (l <= r) {
			R = mid;
		} else {
			L = mid;
		}
	}
	cout << fixed << setprecision(6) << L << endl;
}
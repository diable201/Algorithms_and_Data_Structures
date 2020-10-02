#include <bits/stdc++.h>

using namespace std;

double res(double x) {
    return x * x + sqrt(x);
}

int main() {
    double c;
    cin >> c;
    double l = 0;
    double r = c;
    double eps = 1e-10;
    while (r - l > eps) {
        double m = (l + r) / 2;
        double y = res(m);
        if (y > c)
            r = m;
        else
            l = m;
    }
    cout <<  fixed << setprecision(6) << l << '\n';
}

// #include <bits/stdc++.h>
 
// using namespace std;
 
 
// int main() {	
// 	double c,l,r,m;
// 	cin >> c;
// 	l = 0, r = 1e10;
	
// 	for (int i = 0; i < 500; i++) {
// 		m = (l + r) / 2;
// 		if (m * m + sqrt(m) > c)
//             r = m;
// 		else 
//             l = m;
// 	}
	
// 	cout << fixed << setprecision(20) << m << '\n';
	
// 	return 0;
// }
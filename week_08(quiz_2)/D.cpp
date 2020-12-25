#include <bits/stdc++.h>

using namespace std;

vector <long long> v;

void QuickSort(long long l, long long r) {
    long long i = l;
    long long j = r;
    long long p = v[(l + r) / 2];

    while (i < j) {
        while (v[i] < p) i++;
        while (v[j] > p) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        QuickSort(l, j);
    if (i < r)
        QuickSort(i, r);
}

long long checkProduct(long long i) {
    QuickSort(0, i - 1);
    return v[i - 1] * v[i - 2] * v[i - 3];
}

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
        if (i + 1 < 3)
            cout << -1 << '\n';
        else if (i + 1 == 3)
            cout << v[0] * v[1] * v[2] << '\n';
        else 
            cout << checkProduct(i + 1) << '\n';
    }
    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n;
int a[10000000];

void quicksort(int l, int r) {
    int i = l;
    int j = r;
    int pivot = a[(l + r) / 2];
    while (i < j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(l, j);
    if (i < r)
        quicksort(i, r);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // sort(a, a+n);
    quicksort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
    return 0;
}
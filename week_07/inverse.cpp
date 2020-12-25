#include <bits/stdc++.h>

using namespace std;

int a[1000000];
int res;

void mergesort(int l, int r) {
    if (l >= r)
        return;
    else {
        int mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        int b[r - l + 1];
        while (i <= mid and j <= r) {
            if (a[i] < a[j])
                b[cnt++] = a[i++];
            else {
                b[cnt++] = a[j++];
                res +=  mid - i + 1;
            }
        }
        while (i <= mid)
            b[cnt++] = a[i++];
        while (j <= r)
            b[cnt++] = a[j++];
        for (int i = 0; i < r - l + 1; i++)
            a[l + i] = b[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(0, n - 1);
    cout << res << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
    return 0;
}

// number of inverse
// 5: 3, 4, 1, 5, 2
// inverse = 5: (4,1) (4,2) (3,1) (3, 2) (5, 2)
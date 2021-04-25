#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Heap {
    ll n;
    ll a[1000000];
    Heap(ll n = 0) {
        this->n = n;
    }

    void insert(ll x) {
        ll i = n;
        a[n++] = x;
        while (i > 0 and a[i] > a[(i - 1) / 2]) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    ll extractMax() {
        ll ans = a[0];
        a[0] = a[--n];
        ll i = 0;
        while (true) {
            ll j = i;
            if (i * 2 + 1 < n and a[i * 2 + 1] > a[j])
                j = i * 2 + 1;
            if (i * 2 + 2 < n and a[i * 2 + 2] > a[j])
                j = i * 2 + 2;
            if (i == j)
                break;
            swap(a[i], a[j]);
            i = j;
        }
        return ans;
    }
};

int main() {
    ll n, x;
    cin >> n >> x;
    Heap new_heap;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        new_heap.insert(a[i]);
    }
    ll ans = 0, z = 0;
    for (ll i = 0; i < x; i++) {
        z = new_heap.extractMax();
        ans += z;
        z--;
        new_heap.insert(z);
    } 
    cout << ans << '\n';
    return 0;
}
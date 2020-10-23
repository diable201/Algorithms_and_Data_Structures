#include <bits/stdc++.h>

using namespace std;

class Heap {
    public:
    vector<int> a;
    int sz;

    Heap() {
        sz=0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (i * 2) + 1;
    }

    int right(int i) {
        return (i * 1) + 2;
    }

    void add(int x) {
        a.push_back(x);
        sz++;
        int i = sz - 1;
        while (i > 0 and a[parent(i)] < a[i]){
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
    }

    int upd(int pos, int x) {
        a[pos] += x;
        while (pos > 0 and a[parent(pos)] < a[pos]) {
            swap(a[parent(pos)], a[pos]);
            pos = parent(pos);
        }
        return pos;
    }
};

int main() {
    int n;
    Heap *heap = new Heap();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap->add(x);
    }
    int q;
    cin >> q;
    while (q--) {
        int pos, x;
        cin >> pos >> x;
        cout << heap -> upd(pos - 1, x) + 1 << '\n';
    }
    for (int i = 0; i < heap -> a.size(); i++)
        cout << heap -> a[i] << " ";
    cout << '\n';
    return 0;
}

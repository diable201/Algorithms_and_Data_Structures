#include <iostream>
#include <vector>

using namespace std;

class Heap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        siftUp(a.size() - 1);
    }

    int siftUp(int i) {
        if (i > 0 and a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
            return siftUp(i);
        }
        return i + 1;
    }

    int siftDown(int i) {
        if (left(i) > a.size() - 1)
            return i + 1;

        int j = left(i);
        if (right(i) < a.size() and a[right(i)] > a[left(i)])
            j = right(i);

        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            return siftDown(j);
        }
        return i + 1;
    }


    void decreaseKey(int i, int new_value) {
        a[i] -= new_value;
        cout << siftDown(i) << '\n';
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << '\n';
    }

    int getMin() {
        return a[0];
    }
};

int main() {
    Heap *heap = new Heap();
    uint32_t n, m;
    cin >> n;
    while (n--) {
        uint32_t x;
        cin >> x;
        heap->insert(x);
    }
    cin >> m;
    while (m--) {
        uint32_t y, z;
        cin >> y >> z;
        heap->decreaseKey(y - 1, z);
    }
    heap->print();
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Heap {
    public:
    vector<int> a;
    uint32_t maxSize;
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    Heap(uint32_t maxSize) {
        this->maxSize = maxSize;
    }

    void insert(int k) {
        if (a.size() == maxSize) {
            cout << -1 << '\n';
            return;
        }
        a.push_back(k);
        cout << siftUp(a.size() - 1) << '\n';
        
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

    int deleteNode(int i) {
        if (i < 0 or i > getSize() - 1)
            return -1;
        int root = a[i];
        if (getSize() == 1) {
            a.pop_back();
            return root;
        }
        swap(a[i], a[a.size() - 1]);
        a.pop_back();
        siftUp(i);
        siftDown(i);
        return root;
    }


    void decreaseKey(int i, int new_value) {
        a[i] -= new_value;
        cout << siftDown(i) << '\n';
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
    }

    bool isEmpty() {
        return a.empty();
    }

    int extractMax() {
        if (isEmpty()) return -1;
        int root = a[0];
        if (a.size() == 1) {
            a.pop_back();
            cout << 0 << " ";
            return root;
        }
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        cout << siftDown(0) << " ";
        return root;
    }

    int getSize() {
        return a.size();
    }

    int getMin() {
        return a[0];
    }
};

int main() {
    uint32_t n, m;
    cin >> n >> m;
    Heap *heap = new Heap(n);
    while (m--) {
        uint32_t command;
        cin >> command;
        if (command == 1)
            cout << heap->extractMax() << '\n';
        else if (command == 2) {
            uint32_t x;
            cin >> x;
            heap->insert(x);
        }
        else if (command == 3) {
            uint32_t i;
            cin >> i;
            cout << heap->deleteNode(i - 1) << '\n';
        }
    }
    heap->print();
    cout << '\n';
    return 0;
}
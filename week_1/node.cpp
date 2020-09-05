#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    public:
    Node *top;
    int size;

    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int data) {
        Node *node_new = new Node(data);
        node_new->next = top;
        top = node_new;
        size++;
    }

    void pop() {
        if (top != NULL)
            top = top->next;
            size--;
    }

    int size_of() {
        return size;
    }

    bool empty() {
        return (size == 0);
    }
};

int main() {
    Stack *st = new Stack();
    st->push(20);
    st->push(30);
    st->push(40);
    cout << st->top->data << '\n';
    cout << st->size_of() << '\n';
    cout << st->empty() << '\n';
    st->pop();
    st->pop();
    cout << st->empty() << '\n';
    return 0;
}
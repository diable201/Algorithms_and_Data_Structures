#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node (int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *front, *tail;

    LinkedList() {
        front = NULL;
        tail = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            front = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->next = node;
            node->prev = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail == NULL) 
            return;
        tail = tail->prev;

        if (tail != NULL) 
            tail->next = NULL;
        else 
            front = NULL;
    }

    void pop_front() {
        if (front == NULL) 
            return;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else
            tail = NULL;
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << '\n';
    }

    Node *find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next;
        } 
        return NULL;
    }

    void insert_node(Node *a, int data) {
        if (a == tail)
            push_back(data);
        else {
            Node *b = a->next;
            Node *node = new Node(data);
            a->next = node;
            node->prev = a;
            node->next = b;
            b->prev = node;
        }
    }

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front)
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->push_back(5);
    ll->push_back(6);
    ll->push_front(7);
    ll->push_front(96);
    ll->print();
    cout << ll->front->data << " " << ll->tail->data << '\n';
    Node *node = ll->find_node(6);
    ll->insert_node(node, 100);
    return 0;
}
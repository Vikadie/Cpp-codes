#include <iostream>
using namespace std;

template <typename T>
class dll {
private:
    struct Node {
        Node* prev;
        Node* next;
        T data;
    };

    Node* head;
    Node* tail;

public:
    dll();
    ~dll();

    void insert(T value);

    bool empty() const { return head == tail; };
};

template <typename T> dll<T>::dll() {
    head = nullptr;
    tail = head;
}

template <typename T> dll<T>::~dll() {
    delete[] head;
}

template <typename T> void dll<T>::insert(T value) {
    Node* node = new Node;
    node->data = value;

    // Case 1: There are no nodes yet
    if (head == nullptr) {
        head = node;
        tail = head;
        return;
    }


    // case 2 - inserting at the head of the list
    if (node->data < head->data)
    {
        node->next = head;
        head = node;
        return;
    }

    // case 3 - inserting at the end of the list
    if (node->data >= tail->data)
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
        return;
    }

    // general case - inserting into the middle
    Node* probe = head;
    while (probe && (node->data >= probe->data))
    {
        probe = probe->next;
    }
    if (probe)
    {
        node->next = probe;
        node->prev = probe->prev;
        probe->prev->next = node;
        probe->prev = node;
        return;
    }

    // error - we shouldnt' reach this point. If we did, it meant the list was out of order to begin with.
    return;
}

int main() {
    dll<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(15);
    list.insert(30);
    list.insert(5);
}
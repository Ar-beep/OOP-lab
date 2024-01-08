#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

struct Queue {
    Node *front, *rear;
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr)
            return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();

    std::cout << "Front: " << ((q.front != nullptr) ? q.front->data : -1) << std::endl;
    std::cout << "Rear: " << ((q.rear != nullptr) ? q.rear->data : -1) << std::endl;

    return 0;
}

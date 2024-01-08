#include <iostream>

class Node {
public:
    int data;
    Node* link;

    Node(int n) {
        this->data = n;
        this->link = nullptr;
    }
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int data) {
        Node* temp = new Node(data);
        if (!temp) {
            std::cout << "\nStack Overflow";
            exit(EXIT_FAILURE);
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (!isEmpty())
            return top->data;
        else
            return -1;
    }

    void pop() {
        Node* temp;
        if (top == nullptr) {
            std::cout << "\nStack Underflow" << std::endl;
            return;
        } else {
            temp = top;
            top = top->link;
            free(temp);
        }
    }

    void display() {
        Node* temp;
        if (top == nullptr) {
            std::cout << "\nStack Underflow";
           return;
        } else {
            temp = top;
            while (temp != nullptr) {
                std::cout << temp->data;
                temp = temp->link;
                if (temp != nullptr)
                    std::cout << " -> ";
            }
        }
    }
};

int main() {
    Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.display();
    std::cout << "\nTop element is " << s.peek() << std::endl;
    s.pop();
    s.pop();
    s.display();
    std::cout << "\nTop element is " << s.peek() << std::endl;

    return 0;
}

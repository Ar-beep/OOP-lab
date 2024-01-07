#include <iostream>

template <class T>
class Node
{
public:
    Node *next;
    T data;

public:
    Node(T value) : data(value), next(nullptr) {}
};
template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        clear();
    }

    void append(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {

            Node<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    };
    void display()
    {
        Node<T> *current = head;
        while (current!= nullptr)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
    void clear()
    {
        Node<T> *current = head;
        Node<T> *nextNode;
        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
void addingFirst(T value){
    Node<T>* newNode = new Node<T>(value);
    if(head == nullptr){
        
        head = newNode;

    }
    else{
        Node<T>* temp = head;
        head = newNode;
        newNode->next = temp;
    }
}
void deletespec(T value){
Node<T>* temp = head;


if(head->data == value){
    head = temp->next;
    delete temp;
}
else{
while(temp->next != nullptr){
    temp = temp->next;
    if((temp->next)->data == value){
        break;
    }

}
Node<T>* another =temp->next;
temp->next = (temp->next)->next;
delete another;
}
}


};
int main()
{
    LinkedList<int> lost;
    lost.append(1);
    lost.append(2);
    lost.append(3);
    lost.addingFirst(0);
    lost.addingFirst(-1);
    lost.display();
    lost.clear();
    return 0;
    
}
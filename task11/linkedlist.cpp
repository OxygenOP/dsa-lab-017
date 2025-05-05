#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class QueueLinkedList
{
private:
    Node *front;
    Node *rear;

public:
    QueueLinkedList()
    {
        front = rear = nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (!rear)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
    }

    void display()
    {
        if (!front)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        Node *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    QueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}

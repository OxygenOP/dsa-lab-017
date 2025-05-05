#include "queue.h"
#include <stdexcept>

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

void Queue::enqueue(const std::string &item)
{
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;

    if (rear)
    {
        rear->next = newNode;
        rear = newNode;
    }
    else
    {
        front = rear = newNode;
    }
}

std::string Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    Node *temp = front;
    std::string item = front->data;
    front = front->next;
    if (!front)
    {
        rear = nullptr;
    }
    delete temp;
    return item;
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

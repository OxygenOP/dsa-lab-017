#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class Queue
{
private:
    struct Node
    {
        std::string data;
        Node *next;
    };

    Node *front;
    Node *rear;

public:
    Queue();
    ~Queue();

    void enqueue(const std::string &item);
    std::string dequeue();
    bool isEmpty();
};

#endif

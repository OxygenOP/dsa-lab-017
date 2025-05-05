#include <iostream>
using namespace std;

class QueueArray
{
private:
    int arr[100];
    int front, rear;

public:
    QueueArray()
    {
        front = rear = -1;
    }

    void enqueue(int value)
    {
        if (rear >= 99)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    QueueArray queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}

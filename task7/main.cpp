#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int position)
    {
        if (position == 1)
        {
            insertAtStart(value);
            return;
        }
        Node *temp = head;
        for (int i = 1; temp && i < position - 1; i++)
            temp = temp->next;
        if (!temp)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtCentre(int value)
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int position = (count / 2) + 1;
        insertAtPosition(value, position);
    }

    void displayForward()
    {
        Node *temp = head;
        cout << "Forward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward()
    {
        if (!head)
            return;
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        cout << "Backward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtStart(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(25, 3);
    list.insertAtCentre(15);

    list.displayForward();
    list.displayBackward();

    return 0;
}

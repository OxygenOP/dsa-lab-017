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

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
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
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void merge(LinkedList &other)
    {
        if (!head)
        {
            head = other.head;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = other.head;
    }
};

int main()
{
    LinkedList list1, list2;

    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);

    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    list1.merge(list2);

    cout << "Merged List: ";
    list1.display();

    return 0;
}

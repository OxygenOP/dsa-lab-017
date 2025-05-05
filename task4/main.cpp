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
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtPosition(int value, int position)
    {
        Node *newNode = new Node(value);

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position - 1 && temp; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void displayList()
    {
        Node *temp = head;
        cout << "List: ";
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
    LinkedList list;

    list.insertAtPosition(10, 1); // List: 10
    list.displayList();
    list.insertAtPosition(20, 2); // List: 10 20
    list.displayList();
    list.insertAtPosition(15, 2); // List: 10 15 20
    list.displayList();
    list.insertAtPosition(5, 1); // List: 5 10 15 20
    list.displayList();

    return 0;
}

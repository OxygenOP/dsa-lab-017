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
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayFirst()
    {
        if (head)
            cout << "First node: " << head->data << endl;
        else
            cout << "List is empty." << endl;
    }

    void displayLast()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        cout << "Last node: " << temp->data << endl;
    }

    void displayNth(int n)
    {
        Node *temp = head;
        int count = 1;
        while (temp && count < n)
        {
            temp = temp->next;
            count++;
        }
        if (temp)
            cout << n << "th node: " << temp->data << endl;
        else
            cout << "Position out of range." << endl;
    }

    void displayCentre()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Centre node: " << slow->data << endl;
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

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.displayList();
    list.displayFirst();
    list.displayLast();
    list.displayNth(3);
    list.displayCentre();

    return 0;
}

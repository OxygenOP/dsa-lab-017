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
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteFirst()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNth(int position)
    {
        if (!head)
            return;
        if (position == 1)
        {
            deleteFirst();
            return;
        }
        Node *temp = head;
        for (int i = 1; temp && i < position - 1; i++)
            temp = temp->next;

        if (!temp || !temp->next)
            return;

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void deleteCentre()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete slow;
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

    list.deleteFirst();
    list.displayList();

    list.deleteLast();
    list.displayList();

    list.deleteNth(2);
    list.displayList();

    list.deleteCentre();
    list.displayList();

    return 0;
}

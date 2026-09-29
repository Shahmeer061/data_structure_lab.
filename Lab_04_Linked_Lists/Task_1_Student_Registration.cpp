#include <iostream>
using namespace std;

class Node
{
public:
    int rollNo;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* current;
    int n, roll, search;
    
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Roll Number: ";
        cin >> roll;

        Node* newNode = new Node();
        newNode->rollNo = roll;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
        }
    }

    cout << "\nRegistered Students: ";

    current = head;

    while (current != NULL)
    {
        cout << current->rollNo << " ";
        current = current->next;
    }

    cout << "\n\nEnter Roll Number to Search: ";
    cin >> search;

    current = head;

    while (current != NULL)
    {
        if (current->rollNo == search)
        {
            cout << "Student Found";
            return 0;
        }

        current = current->next;
    }

    cout << "Student Not Found";

    return 0;
}

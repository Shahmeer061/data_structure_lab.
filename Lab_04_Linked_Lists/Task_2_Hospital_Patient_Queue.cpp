#include <iostream>
using namespace std;

class Node
{
public:
    string patientID;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* current;
    int n;
    string id;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Patient ID: ";
        cin >> id;

        Node* newNode = new Node();
        newNode->patientID = id;
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

    cout << "\nWaiting Patients: ";

    current = head;

    while (current != NULL)
    {
        cout << current->patientID << " ";
        current = current->next;
    }

    if (head != NULL)
    {
        cout << "\n\nPatient " << head->patientID << " is being served.";

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << "\n\nUpdated Queue: ";

    current = head;

    while (current != NULL)
    {
        cout << current->patientID << " ";
        current = current->next;
    }

    return 0;
}

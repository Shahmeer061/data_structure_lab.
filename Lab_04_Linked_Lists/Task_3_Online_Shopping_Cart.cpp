#include <iostream>
using namespace std;

class Node
{
public:
    string productID;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* current;
    int n;
    string id, removeID;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Product ID: ";
        cin >> id;

        Node* newNode = new Node();
        newNode->productID = id;
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

    cout << "\nShopping Cart: ";

    current = head;

    while (current != NULL)
    {
        cout << current->productID << " ";
        current = current->next;
    }

    cout << "\n\nRemove Product: ";
    cin >> removeID;

    if (head != NULL && head->productID == removeID)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        current = head;

        while (current != NULL && current->next != NULL)
        {
            if (current->next->productID == removeID)
            {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                break;
            }

            current = current->next;
        }
    }

    cout << "\nUpdated Cart: ";

    current = head;

    while (current != NULL)
    {
        cout << current->productID << " ";
        current = current->next;
    }

    return 0;
}

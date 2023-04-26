#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

void insert(string name) {
    Node* newnode = new Node;
    newnode->name = name;
    newnode->next = head;
    if (head == NULL) {
        head = newnode;
        head->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void remove(Node* kill) 
{
    if (kill == head) 
    {
        head = head->next;
    }
    Node* temp = head;
    while (temp->next != kill) 
    {
        temp = temp->next;
    }
    temp->next = kill->next;
    delete kill;
}

void josephusGame(int n, int k) 
{
    for (int i = 0; i < n; i++) 
    {
        string name;
        cout << "Enter name " << i + 1 << ": ";
        cin >> name;
        insert(name);
    }
    Node* node = head;
    while (node->next != node) 
    { 
        for (int i = 1; i < k; i++) 
        {
            node = node->next;
        }
        cout << "Removed: " << node->name << endl;
        remove(node);
        node = node->next;
    }
    cout << "Winner: " << head->name << endl;
}

int main() 
{
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the step size: ";
    cin >> k;
    josephusGame(n, k);
    return 0;
}

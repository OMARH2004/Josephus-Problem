#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(string name) 
{
    Node* temp = new Node;
    temp->data = name;
    temp->next = NULL;
    if (front == NULL && rear == NULL) 
    {
        front = rear = temp;
        rear->next = front;
        return;
    }
    rear->next = temp;
    rear = temp;
    rear->next = front;
}

void dequeue() 
{
    if (front == NULL) 
    {
        cout << "There are no Players" << endl;
        return;
    }
    if (front == rear) 
    {
        delete front;
        front = rear = NULL;
        return;
    }
    Node* temp = front;
    front = front->next;
    rear->next = front;
    delete temp;
}

void josephus(int n, int s) 
{
    string name;
    for (int i = 1; i <= n; i++) 
    {
        cout << "Enter name " << i << ": ";
        cin >> name;
        enqueue(name);
    }
    while (front->next != front) 
    {
        for (int i = 1; i < s; i++) {
            rear = front;
            front = front->next;
        }
        cout << front->data << " is killed. \n\n";
        dequeue();
    }
    cout << "Winner: " << front->data << endl;
}

int main() 
{
    int n, s;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the no. of steps: ";
    cin >> s;
    josephus(n, s);
    return 0;
}

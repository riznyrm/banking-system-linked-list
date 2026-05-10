#include <iostream>
using namespace std;

class Node {
public:
    int accNo;
    string name;
    float balance;
    Node* next;
};

int main() {

    Node* head = NULL;

    Node* first = new Node();

    first->accNo = 1001;
    first->name = "Rizny";
    first->balance = 5000;
    first->next = NULL;

    head = first;

    cout << "Account Number: " << head->accNo << endl;
    cout << "Name: " << head->name << endl;
    cout << "Balance: " << head->balance << endl;

    return 0;
}
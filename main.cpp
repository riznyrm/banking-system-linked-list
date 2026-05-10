#include <iostream>
using namespace std;

// NODE CLASS
class Node {
public:
    int accNo;
    string name;
    float balance;
    Node* next;
};

// GLOBAL HEAD POINTER
Node* head = NULL;

// CREATE ACCOUNT FUNCTION
void createAccount(int accNo, string name, float balance) {

    // CREATE NEW NODE
    Node* newNode = new Node();

    // STORE DATA
    newNode->accNo = accNo;
    newNode->name = name;
    newNode->balance = balance;

    // LAST NODE POINTS TO NULL
    newNode->next = NULL;

    // IF LINKED LIST IS EMPTY
    if(head == NULL) {
        head = newNode;
    }

    // OTHERWISE ADD NODE AT END
    else {

        Node* temp = head;

        // MOVE TO LAST NODE
        while(temp->next != NULL) {
            temp = temp->next;
        }

        // CONNECT LAST NODE TO NEW NODE
        temp->next = newNode;
    }

    cout << "\nAccount Created Successfully\n";
}

// DISPLAY ALL ACCOUNTS
void displayAccounts() {

    // CHECK EMPTY LIST
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== ACCOUNT LIST =====\n";

    // TRAVERSE LINKED LIST
    while(temp != NULL) {

        cout << "Account No : " << temp->accNo << endl;
        cout << "Name       : " << temp->name << endl;
        cout << "Balance    : " << temp->balance << endl;
        cout << "--------------------------\n";

        // MOVE TO NEXT NODE
        temp = temp->next;
    }
}

// SEARCH ACCOUNT FUNCTION
void searchAccount(int searchAccNo) {

    // CHECK EMPTY LIST
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    // TRAVERSE LINKED LIST
    while(temp != NULL) {

        // CHECK ACCOUNT NUMBER
        if(temp->accNo == searchAccNo) {

            cout << "\n===== ACCOUNT FOUND =====\n";
            cout << "Account No : " << temp->accNo << endl;
            cout << "Name       : " << temp->name << endl;
            cout << "Balance    : " << temp->balance << endl;

            return;
        }

        // MOVE TO NEXT NODE
        temp = temp->next;
    }

    // ACCOUNT NOT FOUND
    cout << "\nAccount Not Found\n";
}

// DEPOSIT MONEY FUNCTION
void depositMoney(int accNo, float amount) {

    // CHECK EMPTY LIST
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    // SEARCH ACCOUNT
    while(temp != NULL) {

        // ACCOUNT FOUND
        if(temp->accNo == accNo) {

            temp->balance = temp->balance + amount;

            cout << "\nMoney Deposited Successfully\n";
            cout << "Updated Balance : " << temp->balance << endl;

            return;
        }

        // MOVE TO NEXT NODE
        temp = temp->next;
    }

    // ACCOUNT NOT FOUND
    cout << "\nAccount Not Found\n";
}

// WITHDRAW MONEY FUNCTION
void withdrawMoney(int accNo, float amount) {

    // CHECK EMPTY LIST
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    // SEARCH ACCOUNT
    while(temp != NULL) {

        // ACCOUNT FOUND
        if(temp->accNo == accNo) {

            // CHECK SUFFICIENT BALANCE
            if(temp->balance >= amount) {

                temp->balance = temp->balance - amount;

                cout << "\nMoney Withdrawn Successfully\n";
                cout << "Remaining Balance : " << temp->balance << endl;
            }

            else {
                cout << "\nInsufficient Balance\n";
            }

            return;
        }

        // MOVE TO NEXT NODE
        temp = temp->next;
    }

    // ACCOUNT NOT FOUND
    cout << "\nAccount Not Found\n";
}

// DELETE ACCOUNT FUNCTION
void deleteAccount(int accNo) {

    // CHECK EMPTY LIST
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // DELETE FIRST NODE
    if(temp->accNo == accNo) {

        head = temp->next;

        delete temp;

        cout << "\nAccount Deleted Successfully\n";

        return;
    }

    // SEARCH NODE
    while(temp != NULL && temp->accNo != accNo) {

        prev = temp;
        temp = temp->next;
    }

    // ACCOUNT NOT FOUND
    if(temp == NULL) {

        cout << "\nAccount Not Found\n";
        return;
    }

    // REMOVE NODE
    prev->next = temp->next;

    // FREE MEMORY
    delete temp;

    cout << "\nAccount Deleted Successfully\n";
}

// TRANSFER MONEY FUNCTION
void transferMoney(int fromAcc, int toAcc, float amount) {

    // CHECK EMPTY LIST
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* sender = NULL;
    Node* receiver = NULL;

    Node* temp = head;

    // SEARCH BOTH ACCOUNTS
    while(temp != NULL) {

        if(temp->accNo == fromAcc) {
            sender = temp;
        }

        if(temp->accNo == toAcc) {
            receiver = temp;
        }

        temp = temp->next;
    }

    // CHECK SENDER
    if(sender == NULL) {
        cout << "\nSender Account Not Found\n";
        return;
    }

    // CHECK RECEIVER
    if(receiver == NULL) {
        cout << "\nReceiver Account Not Found\n";
        return;
    }

    // CHECK SUFFICIENT BALANCE
    if(sender->balance < amount) {
        cout << "\nInsufficient Balance\n";
        return;
    }

    // TRANSFER MONEY
    sender->balance -= amount;
    receiver->balance += amount;

    cout << "\nMoney Transferred Successfully\n";

    cout << "Sender New Balance   : "
         << sender->balance << endl;

    cout << "Receiver New Balance : "
         << receiver->balance << endl;
}

int main() {

    int choice;

    int accNo;
    string name;
    float balance;
    float amount;

    do {

        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Delete Account\n";
        cout << "7. Transfer Money\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice) {

            // CREATE ACCOUNT
            case 1:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Name : ";
                cin >> name;

                cout << "Enter Balance : ";
                cin >> balance;

                createAccount(accNo, name, balance);

                break;

            // DISPLAY ACCOUNTS
            case 2:

                displayAccounts();

                break;

            // SEARCH ACCOUNT
            case 3:

                cout << "\nEnter Account Number To Search : ";
                cin >> accNo;

                searchAccount(accNo);

                break;

            // DEPOSIT MONEY
            case 4:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Amount : ";
                cin >> amount;

                depositMoney(accNo, amount);

                break;

            // WITHDRAW MONEY
            case 5:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Amount : ";
                cin >> amount;

                withdrawMoney(accNo, amount);

                break;

            // DELETE ACCOUNT
            case 6:

                cout << "\nEnter Account Number To Delete : ";
                cin >> accNo;

                deleteAccount(accNo);

                break;

            // TRANSFER MONEY
            case 7: {

                int fromAcc, toAcc;

                cout << "\nEnter Sender Account Number : ";
                cin >> fromAcc;

                cout << "Enter Receiver Account Number : ";
                cin >> toAcc;

                cout << "Enter Amount : ";
                cin >> amount;

                transferMoney(fromAcc, toAcc, amount);

                break;
            }

            // EXIT
            case 8:

                cout << "\nThank You For Using Bank System\n";

                break;

            default:

                cout << "\nInvalid Choice\n";
        }

    } while(choice != 8);

    return 0;
}
#include <iostream>
using namespace std;

// NODE CLASS
class Node {

public:
    int accNo;
    string name;
    float balance;

    Node* next;

    // CONSTRUCTOR
    Node(int accNo, string name, float balance) {

        this->accNo = accNo;
        this->name = name;
        this->balance = balance;

        this->next = NULL;
    }
};

// SINGLY LINKED LIST CLASS
class SinglyLinkedList {

private:

    Node* head;
    Node* tail;

    int size;

public:

    // CONSTRUCTOR
    SinglyLinkedList() {

        head = NULL;
        tail = NULL;

        size = 0;
    }

    // CREATE ACCOUNT
    void createAccount(int accNo, string name, float balance) {

        // CREATE NEW NODE
        Node* newNode = new Node(accNo, name, balance);

        // IF LIST IS EMPTY
        if(head == NULL) {

            head = newNode;
            tail = newNode;
        }

        // INSERT AT END
        else {

            tail->next = newNode;
            tail = newNode;
        }

        size++;

        cout << "\nAccount Created Successfully\n";
    }

    // DISPLAY ACCOUNTS
    void displayAccounts() {

        // CHECK EMPTY LIST
        if(head == NULL) {

            cout << "\nNo Accounts Found\n";
            return;
        }

        Node* temp = head;

        cout << "\n===== ACCOUNT LIST =====\n";

        while(temp != NULL) {

            cout << "Account No : " << temp->accNo << endl;
            cout << "Name       : " << temp->name << endl;
            cout << "Balance    : " << temp->balance << endl;

            cout << "--------------------------\n";

            temp = temp->next;
        }
    }

    // SEARCH ACCOUNT
    void searchAccount(int searchAccNo) {

        // CHECK EMPTY LIST
        if(head == NULL) {

            cout << "\nNo Accounts Found\n";
            return;
        }

        Node* temp = head;

        while(temp != NULL) {

            // ACCOUNT FOUND
            if(temp->accNo == searchAccNo) {

                cout << "\n===== ACCOUNT FOUND =====\n";

                cout << "Account No : " << temp->accNo << endl;
                cout << "Name       : " << temp->name << endl;
                cout << "Balance    : " << temp->balance << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "\nAccount Not Found\n";
    }

    // DEPOSIT MONEY
    void depositMoney(int accNo, float amount) {

        // CHECK EMPTY LIST
        if(head == NULL) {

            cout << "\nNo Accounts Found\n";
            return;
        }

        Node* temp = head;

        while(temp != NULL) {

            // ACCOUNT FOUND
            if(temp->accNo == accNo) {

                temp->balance += amount;

                cout << "\nMoney Deposited Successfully\n";

                cout << "Updated Balance : "
                     << temp->balance << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "\nAccount Not Found\n";
    }

    // WITHDRAW MONEY
    void withdrawMoney(int accNo, float amount) {

        // CHECK EMPTY LIST
        if(head == NULL) {

            cout << "\nNo Accounts Found\n";
            return;
        }

        Node* temp = head;

        while(temp != NULL) {

            // ACCOUNT FOUND
            if(temp->accNo == accNo) {

                // CHECK BALANCE
                if(temp->balance >= amount) {

                    temp->balance -= amount;

                    cout << "\nMoney Withdrawn Successfully\n";

                    cout << "Remaining Balance : "
                         << temp->balance << endl;
                }

                else {

                    cout << "\nInsufficient Balance\n";
                }

                return;
            }

            temp = temp->next;
        }

        cout << "\nAccount Not Found\n";
    }

    // DELETE ACCOUNT
    void deleteAccount(int accNo) {

        // CHECK EMPTY LIST
        if(head == NULL) {

            cout << "\nNo Accounts Found\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // DELETE FIRST NODE
        if(head->accNo == accNo) {

            head = head->next;

            delete temp;

            size--;

            cout << "\nAccount Deleted Successfully\n";

            return;
        }

        // SEARCH NODE
        while(temp != NULL &&
              temp->accNo != accNo) {

            prev = temp;
            temp = temp->next;
        }

        // ACCOUNT NOT FOUND
        if(temp == NULL) {

            cout << "\nAccount Not Found\n";
            return;
        }

        // DELETE LAST NODE
        if(temp == tail) {

            tail = prev;
        }

        // REMOVE NODE
        prev->next = temp->next;

        delete temp;

        size--;

        cout << "\nAccount Deleted Successfully\n";
    }

    // TRANSFER MONEY
    void transferMoney(int fromAcc,
                       int toAcc,
                       float amount) {

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

        // CHECK BALANCE
        if(sender->balance < amount) {

            cout << "\nInsufficient Balance\n";
            return;
        }

        // TRANSFER MONEY
        sender->balance -= amount;
        receiver->balance += amount;

        cout << "\nMoney Transferred Successfully\n";

        cout << "Sender Balance   : "
             << sender->balance << endl;

        cout << "Receiver Balance : "
             << receiver->balance << endl;
    }

    // DISPLAY TOTAL ACCOUNTS
    void totalAccounts() {

        cout << "\nTotal Accounts : "
             << size << endl;
    }
};

// MAIN FUNCTION
int main() {

    SinglyLinkedList bank;

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
        cout << "8. Total Accounts\n";
        cout << "9. Exit\n";

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

                bank.createAccount(accNo,
                                   name,
                                   balance);

                break;

            // DISPLAY ACCOUNTS
            case 2:

                bank.displayAccounts();

                break;

            // SEARCH ACCOUNT
            case 3:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                bank.searchAccount(accNo);

                break;

            // DEPOSIT MONEY
            case 4:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Amount : ";
                cin >> amount;

                bank.depositMoney(accNo,
                                  amount);

                break;

            // WITHDRAW MONEY
            case 5:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Amount : ";
                cin >> amount;

                bank.withdrawMoney(accNo,
                                   amount);

                break;

            // DELETE ACCOUNT
            case 6:

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                bank.deleteAccount(accNo);

                break;

            // TRANSFER MONEY
            case 7: {

                int fromAcc;
                int toAcc;

                cout << "\nEnter Sender Account : ";
                cin >> fromAcc;

                cout << "Enter Receiver Account : ";
                cin >> toAcc;

                cout << "Enter Amount : ";
                cin >> amount;

                bank.transferMoney(fromAcc,
                                   toAcc,
                                   amount);

                break;
            }

            // TOTAL ACCOUNTS
            case 8:

                bank.totalAccounts();

                break;

            // EXIT
            case 9:

                cout << "\nThank You For Using Bank System\n";

                break;

            default:

                cout << "\nInvalid Choice\n";
        }

    } while(choice != 9);

    return 0;
}
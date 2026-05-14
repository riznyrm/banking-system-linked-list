#include <iostream>
using namespace std;


class Node {
public:
    int accNo;
    string name;
    float balance;
    Node* next;
};


Node* head = NULL;

// CREATE ACCOUNT FUNCTION
void createAccount(int accNo, string name, float balance) {

    
    Node* newNode = new Node();

    
    newNode->accNo = accNo;
    newNode->name = name;
    newNode->balance = balance;

    
    newNode->next = NULL;

    
    if(head == NULL) {
        head = newNode;
    }

    
    else {

        Node* temp = head;

        
        while(temp->next != NULL) {
            temp = temp->next;
        }

        
        temp->next = newNode;
    }

    cout << "\nAccount Created Successfully\n";
}

// DISPLAY ALL ACCOUNTS
void displayAccounts() {

    
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

// SEARCH ACCOUNT FUNCTION
void searchAccount(int searchAccNo) {

    
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    
    while(temp != NULL) {

        
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

// DEPOSIT MONEY FUNCTION
void depositMoney(int accNo, float amount) {

    
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    
    while(temp != NULL) {

        
        if(temp->accNo == accNo) {

            temp->balance = temp->balance + amount;

            cout << "\nMoney Deposited Successfully\n";
            cout << "Updated Balance : " << temp->balance << endl;

            return;
        }

        
        temp = temp->next;
    }

    
    cout << "\nAccount Not Found\n";
}

// WITHDRAW MONEY FUNCTION
void withdrawMoney(int accNo, float amount) {

    
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* temp = head;

    
    while(temp != NULL) {

        
        if(temp->accNo == accNo) {

            
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

        
        temp = temp->next;
    }

    
    cout << "\nAccount Not Found\n";
}



// TRANSFER MONEY FUNCTION
void transferMoney(int fromAcc, int toAcc, float amount) {

    
    if(head == NULL) {
        cout << "\nNo Accounts Found\n";
        return;
    }

    Node* sender = NULL;
    Node* receiver = NULL;

    Node* temp = head;

    
    while(temp != NULL) {

        if(temp->accNo == fromAcc) {
            sender = temp;
        }

        if(temp->accNo == toAcc) {
            receiver = temp;
        }

        temp = temp->next;
    }

    
    if(sender == NULL) {
        cout << "\nSender Account Not Found\n";
        return;
    }

    
    if(receiver == NULL) {
        cout << "\nReceiver Account Not Found\n";
        return;
    }

    
    if(sender->balance < amount) {
        cout << "\nInsufficient Balance\n";
        return;
    }

    
    sender->balance -= amount;
    receiver->balance += amount;

    cout << "\nMoney Transferred Successfully\n";

    cout << "Sender New Balance   : "
         << sender->balance << endl;

    cout << "Receiver New Balance : "
         << receiver->balance << endl;
}

int main() {

    char choice;

    int accNo;
    string name;
    float balance;
    float amount;

    do {

        cout << "\n===== WELCOME TO RUHUNA BANK =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Transfer Money\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice) {

            
            case '1':

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Name : ";
                cin >> name;

                cout << "Enter Balance : ";
                cin >> balance;

                createAccount(accNo, name, balance);

                break;

            
            case '2':

                displayAccounts();

                break;

            
            case '3':

                cout << "\nEnter Account Number To Search : ";
                cin >> accNo;

                searchAccount(accNo);

                break;

            
            case '4':

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Amount : ";
                cin >> amount;

                depositMoney(accNo, amount);

                break;

            
            case '5':

                cout << "\nEnter Account Number : ";
                cin >> accNo;

                cout << "Enter Amount : ";
                cin >> amount;

                withdrawMoney(accNo, amount);

                break;


            
            case '6': {

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

            
            case '7':

                cout << "\nThank You For Using Bank System\n";

                break;

            default:

                cout << "\nInvalid Choice\n";
        }

    } while(choice != '7');

    return 0;
}
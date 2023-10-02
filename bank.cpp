#include<bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNum, string accHolder, double initialBalance)
        : accountNumber(accNum), accountHolder(accHolder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account #" << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account #" << accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void transfer(BankAccount& recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transferred $" << amount << " from account #" << accountNumber << " to account #" << recipient.accountNumber << endl;
        } else {
            cout << "Invalid transfer amount or insufficient balance." << endl;
        }
    }

    void display() {
        cout << "Account #" << accountNumber << " (" << accountHolder << "): $" << balance << endl;
    }

    int getAccountNumber(){
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    while (true) {
        cout << "\nBanking Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Display Account Info" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            break;
        }

        switch (choice) {
            case 1: {
                int accNum;
                string accHolder;
                double initialBalance;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, accHolder);
                cout << "Enter Initial Balance: $";
                cin >> initialBalance;
                BankAccount newAccount(accNum, accHolder, initialBalance);
                accounts.push_back(newAccount);
                cout << "Account created successfully." << endl;
                break;
            }
            case 2: {
                int accNum;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Deposit Amount: $";
                cin >> amount;
                for (BankAccount& acc : accounts) {
                    if (accNum == acc.getAccountNumber()) {
                        acc.deposit(amount);
                        break;
                    }
                }
                break;
            }
            case 3: {
                int accNum;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Withdrawal Amount: $";
                cin >> amount;
                for (BankAccount& acc : accounts) {
                    if (accNum == acc.getAccountNumber()) {
                        acc.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                int senderAccNum, recipientAccNum;
                double amount;
                cout << "Enter Sender Account Number: ";
                cin >> senderAccNum;
                cout << "Enter Recipient Account Number: ";
                cin >> recipientAccNum;
                cout << "Enter Transfer Amount: $";
                cin >> amount;

                BankAccount* sender = nullptr;
                BankAccount* recipient = nullptr;

                for (BankAccount& acc : accounts) {
                    if (senderAccNum == acc.getAccountNumber()) {
                        sender = &acc;
                    }
                    if (recipientAccNum == acc.getAccountNumber()) {
                        recipient = &acc;
                    }
                }

                if (sender != nullptr && recipient != nullptr) {
                    sender->transfer(*recipient, amount);
                } else {
                    cout << "Invalid account numbers." << endl;
                }
                break;
            }
            case 5: {
                int accNum;
                int flag=0;
                cout << "Enter Account Number: ";
                cin >> accNum;
                for (BankAccount& acc : accounts) {
                    if (accNum == acc.getAccountNumber()) {
                        flag++;
                        acc.display();
                        break;
                    }
                }
                if(flag == 0){
                    cout<<"Account Number is not there in our bank please create it";
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include "BankAccount.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    int selection = 0;
    int *const selectionPtr = &selection;
    cout << "\n*WELCOME TO THE BANKING SYSTEM*" << endl;
    while (*selectionPtr != 7) {
        cout << "\nSelect an option below: "
             << "\n1. Open an Account"
             << "\n2. Balance Enquiry"
             << "\n3. Deposit Funds"
             << "\n4. Withdraw Funds"
             << "\n5. Close an Account"
             << "\n6. Show All Accounts"
             << "\n7. Quit" << endl;
        cin >> *selectionPtr;
        switch (*selectionPtr) {
            case 1:
                BankAccount::createAccount();
                break;
            case 2:
                BankAccount::checkBalance();
                break;
            case 3:
                BankAccount::depositFunds();
                break;
            case 4:
                BankAccount::withdrawFunds();
                break;
            case 5:
                BankAccount::closeAccount();
                break;
            case 6:
                BankAccount::displayAllAccounts();
                break;
            case 7: {
                BankAccount::saveAllToFile();

                // Delete all vector pointers.
                vector<BankAccount *>::iterator iter;
                for (iter = BankAccount::accountList.begin(); iter != BankAccount::accountList.end(); iter++) {
                    delete *iter;
                }
                cout << "We hope to see you again! Goodbye!" << endl;
                break;
            }
            default:
                cout << "*Please enter a valid option (1~7)*" << endl;
                break;
        }
    }
    delete selectionPtr;
    return 0;
}

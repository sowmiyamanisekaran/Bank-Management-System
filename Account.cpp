#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::endl;
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ostream;

vector<BankAccount *> BankAccount::accountList = BankAccount::loadAllAccounts();
long BankAccount::latestAccountNumber = BankAccount::getMaxAccountNumber();

BankAccount::BankAccount(string userFirstName, string userLastName, const long &balanceAmount) :
        firstName(std::move(userFirstName)),
        lastName(std::move(userLastName)),
        balance(balanceAmount),
        accountNumber(++latestAccountNumber) {
}

BankAccount::BankAccount(const long &accountNum, string userFirstName, string userLastName, const long &balanceAmount) :
        firstName(std::move(userFirstName)),
        lastName(std::move(userLastName)),
        balance(balanceAmount),
        accountNumber(accountNum) {
}

BankAccount::BankAccount(const BankAccount &account) :
        firstName(account.getFirstName()),
        lastName(account.getLastName()),
        balance(account.getBalance()),
        accountNumber(++latestAccountNumber) {
}

void BankAccount::setFirstName(const string &firstName) const {
    this->firstName = firstName;
}

void BankAccount::setLastName(const string &lastName) const {
    this->lastName = lastName;
}

void BankAccount::setBalance(const long &amount) const {
    this->balance = amount;
}

const long &BankAccount::getAccountNumber() const {
    return accountNumber;
}

const string &BankAccount::getFirstName() const {
    return firstName;
}

const string &BankAccount::getLastName() const {
    return lastName;
}

const long &BankAccount::getBalance() const {
    return balance;
}

vector<BankAccount *> BankAccount::loadAllAccounts() {
    vector<BankAccount *> accountList;
    ifstream inputFile;
    inputFile.open("account_data.txt");
    if (!inputFile)
        return {};
    while (!inputFile.eof())
        inputFile >> accountList;
    return accountList;
}

long BankAccount::getMaxAccountNumber() {
    return BankAccount::accountList.empty() ? 0 : (*BankAccount::accountList.back()).getAccountNumber();
}

void BankAccount::createAccount() {
    string userFirstName;
    string userLastName;
    cout << "\n*CREATE ACCOUNT*" << endl;
    cout << "First Name: " << endl;
    cin >> userFirstName;
    cout << "Last Name: " << endl;
    cin >> userLastName;
    long balanceAmount;
    cout << "Initial Balance: " << endl;
    cin >> balanceAmount;
    accountList.push_back(new BankAccount("", "", 0));
    accountList.back()->setFirstName(userFirstName);
    accountList.back()->setLastName(userLastName);
    accountList.back()->setBalance(balanceAmount);
    cout << *accountList.back() << endl;
    ofstream outputFile("account_data.txt", ios::app);
    outputFile << *accountList.back();
    outputFile.close();
}

BankAccount *BankAccount::findByAccountNumber(const long &accountNum) {
    vector<BankAccount *>::iterator iter;
    iter = find_if(accountList.begin(), accountList.end(),
                  [&](auto accountPtr) { return compareAccountNumbers(accountPtr, accountNum); });
    if (iter != accountList.end())
        return *iter;
    else {
        BankAccount *ptr = nullptr;
        return ptr;
    }
}

void BankAccount::checkBalance() {
    long accountNumber;
    cout << "\n*CHECK BALANCE*" << endl;
    cout << "Enter Account Number: " << endl;
    cin >> accountNumber;
    BankAccount *accountPtr = findByAccountNumber(accountNumber);
    if (accountPtr != nullptr)
        cout << *accountPtr << endl;
    else
        cout << "Account Not Found. " << endl;
}

void BankAccount::saveAllToFile() {
    ofstream outputFile("account_data.txt", ios::trunc);
    for (auto account : accountList)
        outputFile << *account;
    outputFile.close();
}

void BankAccount::depositFunds() {
    long accountNumber;
    long depositAmount;
    cout << "\n*DEPOSIT FUNDS*" << endl;
    cout << "Enter Account Number: " << endl;
    cin >> accountNumber;
    BankAccount *accountPtr = findByAccountNumber(accountNumber);
    if (accountPtr != nullptr) {
        cout << *accountPtr << endl;
        cout << "\nEnter Deposit Amount: " << endl;
        cin >> depositAmount;
        accountPtr->setBalance(depositAmount + accountPtr->getBalance());
        cout << "Amount " << depositAmount << " has been deposited into Account Number " << accountNumber << endl;
        saveAllToFile();
        cout << *accountPtr << endl;
    } else
        cout << "Account Not Found. " << endl;
}

void BankAccount::withdrawFunds() {
    long accountNumber;
    long withdrawalAmount;
    cout << "\n*WITHDRAW FUNDS*" << endl;
    cout << "Enter Account Number: " << endl;
    cin >> accountNumber;
    BankAccount *accountPtr = findByAccountNumber(accountNumber);
    if (accountPtr != nullptr) {
        cout << *accountPtr << endl;
        cout << "\nEnter Withdrawal Amount: " << endl;
        cin >> withdrawalAmount;
        accountPtr->setBalance(accountPtr->getBalance() - withdrawalAmount);
        cout << "Amount " << withdrawalAmount << " has been withdrawn from Account Number " << accountNumber << endl;
        saveAllToFile();
        cout << *accountPtr << endl;
    } else
        cout << "Account Not Found. " << endl;
}

void BankAccount::closeAccount() {
    cout << "\n*CLOSE ACCOUNT*" << endl;
    long accountNumber;
    cout << "Enter Account Number: " << endl;
    cin >> accountNumber;
    BankAccount *accountPtr = findByAccountNumber(accountNumber);
    if (accountPtr != nullptr) {
        vector<BankAccount *>::iterator iter;
        for (iter = accountList.begin(); iter < accountList.end(); ++iter) {
            if ((*iter)->getAccountNumber() == accountNumber) {
                cout << **iter << endl;
                accountList.erase(iter);
            }
        }
        saveAllToFile();
        cout << "Account Number " << accountNumber << " has been closed." << endl;
    } else
        cout << "Account Not Found. " << endl;
}

void BankAccount::displayAllAccounts() {
    cout << "\n*DISPLAY ALL ACCOUNTS*";
    for (auto accountPtr : accountList)
        cout << *accountPtr << endl;
}

BankAccount::~BankAccount() = default;

ifstream const &operator>>(ifstream &inputFile, vector<BankAccount *> &accountList) {
    long accountNumber;
    string firstName;
    string lastName;
    long balanceAmount;
    inputFile >> accountNumber >> firstName >> lastName >> balanceAmount;
    accountList.push_back(new BankAccount(accountNumber, firstName, lastName, balanceAmount));
    return inputFile;
}

ostream &operator<<(ostream &outputStream, const BankAccount &account) {
    outputStream << "\nAccount Number: " << account.getAccountNumber() << endl
                 << "First Name: " << account.getFirstName() << endl
                 << "Last Name: " << account.getLastName() << endl
                 << "Balance: " << account.getBalance();
    return outputStream;
}

const ofstream &operator<<(ofstream &outputFile, const BankAccount &account) {
    outputFile << "\n"
               << account.getAccountNumber() << endl
               << account.getFirstName() << endl
               << account.getLastName() << endl
               << account.getBalance();
    return outputFile;
}

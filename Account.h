#ifndef CPP_BANKING_SYSTEM_BANKACCOUNT_H
#define CPP_BANKING_SYSTEM_BANKACCOUNT_H

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;

class BankAccount {
private:
    static long currentAccountNumber;
    long accountNumber;
    mutable string firstName;
    mutable string lastName;
    mutable long balance;

public:
    static vector<BankAccount *> accountList;

    BankAccount(string userFirstName, string userLastName, const long &balanceAmount);

    BankAccount(const long &accountNum, string userFirstName, string userLastName, const long &balanceAmount);

    BankAccount() : BankAccount(getAccountNumber(), "", "", 0L) {};

    BankAccount(const BankAccount &account);

    void setFirstName(const string &firstName) const;

    void setLastName(const string &lastName) const;

    void setBalance(const long &amount) const;

    const long &getAccountNumber() const;

    const string &getFirstName() const;

    const string &getLastName() const;

    const long &getBalance() const;

    static long getMaxAccountNumber(); // Retrieve account info and get the latest account number

    static vector<BankAccount *> loadAllAccounts();

    friend const ifstream &operator>>(ifstream &inputFile, vector<BankAccount *> &accountList);

    friend ostream &operator<<(ostream &outputStream, const BankAccount &account);

    friend const ofstream &operator<<(ofstream &outputFile, const BankAccount &account);

    static void createAccount();

    static bool compareAccountNumbers(const BankAccount *accountPtr, const long &accountNum) {
        return (*accountPtr).getAccountNumber() == accountNum;
    }

    static BankAccount *findByAccountNumber(const long &accountNum);

    static void checkBalance();

    static void saveAllToFile();

    static void depositFunds();

    static void withdrawFunds();

    static void closeAccount();

    static void displayAllAccounts();

    ~BankAccount();
};

#endif //CPP_BANKING_SYSTEM_BANKACCOUNT_H

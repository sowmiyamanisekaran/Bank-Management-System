# Bank Management System 💼🏦

Welcome to the **Bank Management System** repository! This project simulates a simple banking application where users can perform various banking operations such as opening an account, checking balance, depositing, withdrawing, and closing accounts. It's designed to be easy to use while demonstrating the power of object-oriented programming in C++.

## Table of Contents 📚
- [Overview](#overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [How to Run](#how-to-run)
- [Project Structure](#project-structure)
- [Classes and Functions](#classes-and-functions)
- [Contributing](#contributing)
- [License](#license)

## Overview 🏦
The **Bank Management System** allows users to manage their accounts using a series of options. It simulates real-world banking operations and demonstrates key concepts like:
- Object-Oriented Programming (OOP)
- File Handling
- Dynamic Memory Management
- C++ Standard Library usage (vectors, strings, streams)

The system stores account data in a text file (`bank_ledger.txt`), which is updated whenever a new transaction or account operation is performed. Account information includes account number, first name, last name, and account balance.

## Features 🌟
Here are the main features of this project:

- **Account Operations**:
  - Open an Account 📑
  - Check Account Balance 💰
  - Deposit Funds 💵
  - Withdraw Funds 💸
  - Close an Account ❌
  
- **Display All Accounts**:
  - View a list of all accounts in the system 🔍
  
- **Persistent Data Storage**:
  - All transactions and account information are stored in a text file (`bank_ledger.txt`) for persistence 📝

- **Easy to Use Interface**:
  - Simple menu-based interface for easy interaction with the system 👨‍💻

## Technologies Used 💻
- **C++**: The main programming language for implementing the system.
- **Standard Template Library (STL)**: Used for vectors, strings, file I/O operations, etc.
- **File Handling**: Bank account data is stored in and retrieved from `bank_ledger.txt`.

## How to Run 🏃‍♂️
### Prerequisites:
- Ensure that you have a C++ compiler installed on your machine. For example, you can use **g++** (GNU C++ compiler).

### Instructions:
1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/banking-system.git
    cd banking-system
    ```

2. Compile the program:
    ```bash
    g++ -o bank_app main.cpp Account.cpp
    ```

3. Run the program:
    ```bash
    ./bank_app
    ```

The program will start, and you'll be presented with a menu to choose various banking operations.

## Project Structure 🏗️

Here’s an overview of the project structure:

```
banking-system/
│
├── Account.h             # Header file for the BankAccount class
├── Account.cpp           # Implementation of the BankAccount class
├── main.cpp              # Main entry point for the application
├── bank_ledger.txt       # Text file to store account data
├── README.md             # This file (you're reading it right now)
└── Makefile (optional)   # To simplify the build process
```

## Classes and Functions 🧑‍💻

### `BankAccount` Class 🏦

The core of the system is the `BankAccount` class, which encapsulates all the information and actions associated with a bank account. It includes the following attributes and functions:

#### Attributes:
- `accountNumber`: A unique identifier for each account.
- `firstName`: The account holder's first name.
- `lastName`: The account holder's last name.
- `balance`: The balance of the account.

#### Static Attributes:
- `accountList`: A static vector that holds all the bank account objects.
- `currentAccountNumber`: A static long variable that keeps track of the last account number used.

#### Member Functions:
- **`open()`**: Allows the user to open a new account. The details are taken as input, and the account is added to the system.
- **`checkBalance()`**: Displays the balance of a specified account.
- **`depositFunds()`**: Deposits a specified amount into an account.
- **`withdrawFunds()`**: Withdraws a specified amount from an account.
- **`closeAccount()`**: Closes an account and removes it from the system.
- **`displayAllAccounts()`**: Displays a list of all the accounts in the system.
- **`saveAllToFile()`**: Saves the current state of all accounts to the `bank_ledger.txt` file.
- **`findByAccountNumber()`**: Searches for an account by its unique account number.

#### Friend Functions:
- **`operator<<`**: Outputs the account details to the stream (for printing and file storage).
- **`operator>>`**: Reads account details from the stream (for loading accounts from the file).

## How the Program Works 🔧
1. **User Interface**:
    - The program begins with a menu that allows the user to choose an operation (e.g., Open an Account, Balance Enquiry, etc.).
  
2. **Banking Operations**:
    - Depending on the user’s choice, the appropriate function is called to perform actions like depositing, withdrawing, or checking the balance.

3. **Data Persistence**:
    - Each account's data is saved to a file (`bank_ledger.txt`) upon every update or transaction. This ensures that the data is persistent across multiple program executions.

4. **Memory Management**:
    - Memory for bank accounts is dynamically allocated, and the program ensures that this memory is deallocated properly before exiting, preventing memory leaks.

## Contributing 🤝

We welcome contributions! If you'd like to contribute to the project, feel free to:
1. Fork the repository.
2. Create a new branch for your changes.
3. Commit your changes.
4. Open a Pull Request.

Please make sure that your code follows the existing style and is well-documented.

## License 📝

This project is open source and available under the MIT License. See the [LICENSE](LICENSE) file for more information.

---

We hope you find this project useful for learning and practical use! ✨

For any issues or questions, feel free to open an issue or contact us directly. 

Happy Banking! 😄

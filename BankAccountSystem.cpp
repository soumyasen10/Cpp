#include <iostream>
#include <string>
#include <unordered_map>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor to initialize account
    BankAccount(const std::string& accNum, const std::string& holderName, double initialBalance) 
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid amount." << std::endl;
        }
    }

    // Function to display account details
    void display() const {
        std::cout << "Account Number: " << accountNumber << "\n"
                  << "Account Holder: " << accountHolderName << "\n"
                  << "Balance: " << balance << std::endl;
    }

    // Function to get account number
    std::string getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    std::unordered_map<std::string, BankAccount> accounts;

public:
    // Function to create a new account
    void createAccount(const std::string& accNum, const std::string& holderName, double initialBalance) {
        if (accounts.find(accNum) == accounts.end()) {
            accounts[accNum] = BankAccount(accNum, holderName, initialBalance);
            std::cout << "Account created successfully." << std::endl;
        } else {
            std::cout << "Account with this number already exists." << std::endl;
        }
    }

    // Function to find an account by account number
    BankAccount* findAccount(const std::string& accNum) {
        if (accounts.find(accNum) != accounts.end()) {
            return &accounts[accNum];
        } else {
            std::cout << "Account not found." << std::endl;
            return nullptr;
        }
    }
};

int main() {
    Bank bank;

    // Creating accounts
    bank.createAccount("123456", "John Doe", 1000.0);
    bank.createAccount("654321", "Jane Smith", 500.0);

    // Finding and displaying account details
    BankAccount* account = bank.findAccount("123456");
    if (account) {
        account->display();
    }

    // Depositing money
    account = bank.findAccount("123456");
    if (account) {
        account->deposit(200.0);
    }

    // Withdrawing money
    account = bank.findAccount("123456");
    if (account) {
        account->withdraw(150.0);
    }

    // Trying to withdraw more than balance
    account = bank.findAccount("123456");
    if (account) {
        account->withdraw(1200.0);
    }

    // Displaying details of another account
    account = bank.findAccount("654321");
    if (account) {
        account->display();
    }

    return 0;
}

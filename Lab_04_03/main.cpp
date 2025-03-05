#include <iostream>
#include <memory>

class BankAccount {
private:
    unsigned long _balance;
public:
    BankAccount(const long starting_balance): _balance(starting_balance) {}


    long get_balance_copy() {
        return _balance;
    }

    // Unsafe
    unsigned long& get_balance_unsafe() {
        return _balance;
    }

    const long& get_balance() const {
        return _balance;
    }


    void set_balance(const long balance) {
        if(balance >= 0) {
            _balance = balance;
        }
    }

};

int main() {
    BankAccount account(420);
    std::cout << "The account has a balance of " << account.get_balance() << std::endl;
    account.set_balance(69);
    std::cout << "The account has a balance of " << account.get_balance() << std::endl;

    return 0;
}


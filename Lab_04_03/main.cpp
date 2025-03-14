#include <iostream>
#include <memory>

class BankAccount {
private:
    unsigned long _balance;
public:
    BankAccount(const unsigned long starting_balance): _balance(starting_balance) {}

    const unsigned long& get_balance() const {
        return _balance;
    }


    void set_balance(const unsigned long balance) {
        if(balance >= 0) {
            _balance = balance;
        }
    }

    void deposit(const unsigned long ammount) {
        if(ammount > 0) {
            _balance += ammount;
        }
    }

    void withdraw(const unsigned long amount) {
        //if(amount > 0 && amount <= _balance) {
            //_balance -= amount;
        //}

        // Guard Satements
        if(amount > _balance) {
            return;
        }

        if(amount > 1000000){
            return;
        }

        _balance -= amount;
    } 

};

int main() {
    BankAccount account(420);
    std::cout << "The account has a balance of " << account.get_balance() << std::endl;
    account.set_balance(69);
    std::cout << "The account has a balance of " << account.get_balance() << std::endl;
    account.withdraw(100000);

    return 0;
}


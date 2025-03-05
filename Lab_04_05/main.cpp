#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <map>

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
    std::array <BankAccount, 4> arr = {
        BankAccount{1}, BankAccount{2},
        BankAccount{3}, BankAccount{4}
    };

    for(const auto& account : arr) {
        std::cout << account.get_balance() << std::endl;
    }

    std::map<std::string, BankAccount> accounts;
    accounts.insert({"11123123", BankAccount(420)});

    for(const auto& elem : accounts) {
        std::cout << elem.first << " " << elem.second.get_balance();
    }

    for(const auto& [account_number, account] : accounts) {
        std::cout << account_number << " " << account.get_balance();
    }

    return 0;
}


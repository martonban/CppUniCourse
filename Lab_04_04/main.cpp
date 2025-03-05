#include <iostream>
#include <memory>
#include <vector>

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
    std::vector<BankAccount> accounts;
    accounts.emplace_back(BankAccount(1));
    accounts.emplace_back(BankAccount(2));
    accounts.emplace_back(BankAccount(3));
    accounts.emplace_back(BankAccount(4));
    std::cout << "Size = " << accounts.size() << " Capacity = " << accounts.capacity() << std::endl;
    
    for(int i = 0; i < accounts.size(); i++) {
        std::cout << accounts[i].get_balance() << std::endl;
    }

    for(BankAccount acc : accounts) {
        std::cout << acc.get_balance() << std::endl;
    }
    
    std::cout << "#####################\n";

    for(const auto& acc : accounts) {
        std::cout << acc.get_balance() << std::endl;
    }

    auto ptr = std::make_unique<BankAccount>(129);

    std::vector<double> d{3, 2, 1, 0};


    for(const auto& value : d) {
        std::cout << value << std::endl;
    }



    
    return 0;
}


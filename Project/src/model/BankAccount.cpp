#include "model/BankAccount.hpp"

namespace bank {
    BankAccount::BankAccount(const std::string& id, const long initial_balance)
        : _id(id), _balance(initial_balance) {
    }

    BankAccount::BankAccount(std::string&& id, const long initial_balance)
        : _id(std::move(id)), _balance(initial_balance) {
    }

    BankAccount::BankAccount(const std::string& id) : BankAccount(id, 0) {
    }

    BankAccount::BankAccount(std::string&& id) : BankAccount(std::move(id), 0) {
    }

    long BankAccount::get_balance() const noexcept {
        return _balance;
    }

    const std::string& BankAccount::get_id() const noexcept {
        return _id;
    }

    void BankAccount::deposit(const long amount) noexcept {
        if (amount > 0)
            _balance += amount;
    }

    void BankAccount::withdraw(const long amount) noexcept {
        if (amount > 0 && amount <= _balance)
            _balance -= amount;
    }
} // namespace bank
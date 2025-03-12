#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <string>

namespace bank {
    class BankAccount {
      private:
        std::string _id;
        long _balance;

      public:
        BankAccount(const std::string& id, const long initial_balance);
        BankAccount(std::string&& id, const long initial_balance);
        BankAccount(const std::string& id);
        BankAccount(std::string&& id);

        const std::string& get_id() const noexcept;
        long get_balance() const noexcept;

        void deposit(const long amount) noexcept;
        void withdraw(const long amount) noexcept;
    };
} // namespace bank

#endif // BANK_ACCOUNT_HPP
#include <array>
#include <limits>
#include <map>
#include <memory>
#include <print>
#include <vector>

#include "model/BankAccount.hpp"

int main() {
    std::map<std::string, bank::BankAccount> accounts;
    accounts.insert({"12341234", bank::BankAccount("1234123", 420)});
    for (const auto& [account_number, account] : accounts) {
        std::println("{} : {}", account_number, account.get_balance());
    }
}
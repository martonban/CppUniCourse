#include <catch2/catch_all.hpp>

#include "model/BankAccount.hpp"

TEST_CASE("BankAccount account id only constructor",
          "[bank_account][constructor]")
{
    std::string id("test_id");
    bank::BankAccount bank_account(id);
    REQUIRE(bank_account.get_id() == "test_id");
    REQUIRE(bank_account.get_balance() == 0);
}

TEST_CASE("BankAccount account id, balance constructor",
          "[bank_account][constructor]")
{
    std::string id("test_id");
    bank::BankAccount bank_account(id, 100);
    REQUIRE(bank_account.get_id() == "test_id");
    REQUIRE(bank_account.get_balance() == 100);
}

TEST_CASE("BankAccount rvalue account id only constructor",
          "[bank_account][constructor]")
{
    bank::BankAccount bank_account("test_id");
    REQUIRE_THAT(bank_account.get_id(), Catch::Matchers::Equals("test_id"));
    REQUIRE(bank_account.get_balance() == 0);

    BENCHMARK("BankAccount getter benchmark")
    {
        return bank_account.get_balance();
    };
}

TEST_CASE("BankAccount rvalue account id, balance constructor",
          "[bank_account][constructor]")
{
    bank::BankAccount bank_account("test_id", 100);
    REQUIRE(bank_account.get_id() == "test_id");
    REQUIRE(bank_account.get_balance() == 100);
}

TEST_CASE("BankAccount withdraw within funds", "[bank_account][withdraw]")
{
    bank::BankAccount bank_account("test_id", 100);

    bank_account.withdraw(10);

    REQUIRE(bank_account.get_balance() == 90);
}

TEST_CASE("BankAccount withdraw outside funds", "[bank_account][withdraw]")
{
    bank::BankAccount bank_account("test_id", 100);

    bank_account.withdraw(110);

    REQUIRE(bank_account.get_balance() == 100);
}

TEST_CASE("BankAccount withdraw total funds", "[bank_account][withdraw]")
{
    bank::BankAccount bank_account("test_id", 100);

    bank_account.withdraw(100);

    REQUIRE(bank_account.get_balance() == 0);
}

TEST_CASE("BankAccount multiple withdraw within funds",
          "[bank_account][withdraw]")
{
    bank::BankAccount bank_account("test_id", 100);

    bank_account.withdraw(10);

    REQUIRE(bank_account.get_balance() == 90);

    bank_account.withdraw(20);

    REQUIRE(bank_account.get_balance() == 70);
}

TEST_CASE("BankAccount withdraw negative amount does not change balance",
          "[bank_account][withdraw]")
{
    bank::BankAccount bank_account("test_id", 100);

    bank_account.withdraw(-10);

    REQUIRE(bank_account.get_balance() == 100);
}

TEST_CASE("BankAccount deposit positive amount", "[bank_account][deposit]")
{
    bank::BankAccount bank_account("test_id", 100);

    bank_account.deposit(10);

    REQUIRE(bank_account.get_balance() == 110);
}
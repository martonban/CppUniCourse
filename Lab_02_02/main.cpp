#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> res1 = std::make_unique<int>(1);
    std::unique_ptr<int> res2 = std::move(res1);
    std::cout << *res2 << std::endl;

}
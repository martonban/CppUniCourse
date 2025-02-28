#include <iostream>
#include <memory>

struct A {
    A () {
        std::cout << "A Constructed\n";
    }
};

struct B : virtual public A {
    B() {
        std::cout << "B constructed\n";
    }
};

struct C : virtual public A {
    C() {
        std::cout << "C constructed\n";
    }
};

struct D : public B, public C{
    D() {
        std::cout << "D constructed\n";
    }
};

int main(int argc, char const* argv[]) {
    D d;
    return 0;
}   
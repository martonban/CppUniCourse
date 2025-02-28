#include <iostream>
#include <memory>



class Base {
public:    
    Base() { std::cout << "Base Constructor" << std::endl; }
    virtual void greet() {std::cout << "Base: yo!" << std::endl;}
    // MINDIG VIRTUÁLSI DESTRUKOT
    virtual ~Base() {std::cout << "Base destroyed" << std::endl;}
};

class Derived : public Base {
private:
    int * data;
public:
    Derived(int num) {
        std::cout << "Derived Constructor" << std::endl;
        data = new int;
        *data = num;
    }
    void greet() override {std::cout << "Derived: yo!" << std::endl;}
    ~Derived() {
        std::cout << "Derived destroyed" << std::endl;
        delete data;
    }
};

int main() {
    //Base* obj = new Derived(3);
    //obj -> greet();
    //delete obj;
    std::unique_ptr<Base> obj = std::make_unique<Derived>(2);
    obj -> greet();
}


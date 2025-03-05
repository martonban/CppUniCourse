#include <iostream>
#include <memory>

class ResourceManager {
private:
    std::shared_ptr<int> data;
public:
    ResourceManager(int i) {
        data = std::make_shared<int>(i);
    }
    
    int get_data() {
        return *data;
    }

    void set_data(int i) {
        *data = i;
    }
};

int main() {
    ResourceManager rm(420);
    std::cout << rm.get_data() << std::endl;
    // Not goig to work becuse until the make_unique, We need to use shered pointer
    ResourceManager rm2 = rm; 
    rm2.set_data(69);
    std::cout << rm2.get_data() << std::endl;
    return 0;
}
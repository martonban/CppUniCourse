#include <iostream>

struct ResourceManger {
    size_t size;
    int* data;

    // Constructor
    ResourceManger(size_t size);

    // RULE OF THREE
    // Copy Constructor
    ResourceManger(const ResourceManger& other);

    // Copy Assignment
    ResourceManger& operator=(const ResourceManger& other);

    // RULE OF FIVE
    // Move Constructor
    ResourceManger(ResourceManger&& other) noexcept;

    // Move Assignment
    ResourceManger& operator=(ResourceManger&& other) noexcept;

    ~ResourceManger();

};

ResourceManger::ResourceManger(size_t size): size(size) {
    std::cout << "Created" << std::endl;
    data = new int[size];
};

ResourceManger::~ResourceManger() {
    std::cout << "Deleted" << std::endl;
    delete[] data;
}

// Copy Constructor
ResourceManger::ResourceManger(const ResourceManger& other) : size(other.size) {
    if(this != &other) {

        data = new int[size];
        std::copy(other.data, other.data + size, data);

        std::cout << "[COPY Constructor] copied" << std::endl;
    }
}

// Copy Assignment
ResourceManger& ResourceManger::operator=(const ResourceManger& other) {
    if(this != &other) {
        this->size = other.size;
        delete[] data;

        data = new int[size];
        std::copy(other.data, other.data + size, data);

        std::cout << "[COPY Constructor] copied" << std::endl;
    }
    return *this;
}


ResourceManger::ResourceManger(ResourceManger&& other) noexcept : size(other.size), data(other.data) {
    other.data = nullptr;
    other.size = 0;

    std::cout << "[Move Constructor]" << std::endl;
}

ResourceManger& ResourceManger::operator=(ResourceManger&& other) noexcept {
    if(this != &other) {
        this->size = other.size;
        this->data = other.data;


        other.data = nullptr;
        other.size = 0;

        std::cout << "[COPY Constructor] copied" << std::endl;
    }
    return *this;
}

int main() {
   ResourceManger res1(10);

   ResourceManger res2 = res1;
   
   ResourceManger res3 = std::move(res1);
   res2 = res3;
   
   
   /*
    ResourceManger rn(1);
    ResourceManger rn2 = rn;
    // C++ 11 move -> move
    ResourceManger rn3 = std::move(rn);
    */
}
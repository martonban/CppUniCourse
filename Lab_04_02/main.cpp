#include <iostream>
#include <memory>

struct Node {
    int value;
    std::shared_ptr<Node> next;
    // We need a weak pointer able to destroy line 24-25 connection
    std::weak_ptr<Node> prev;

    Node (int val) : value(val) {
        std::cout << "Node Constructed with " << value << std::endl; 
    }

    ~Node() {
        std::cout << "Node Destroyed with " << value << std::endl; 
    }

};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2);

    node1->next = node2;
    node2->prev = node1;

    std::cout << "Node1 Value " << node1->value << std::endl;
    std::cout << "Node2 Value " << node2->value << std::endl;

    return 0;

}
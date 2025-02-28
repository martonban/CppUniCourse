#include <iostream>
#include <memory>

class Shape {
    public:
        Shape() {
            std::cout << "Shape Constructed" << std::endl;
        };
        virtual void draw() { std::cout << "Draw Shape" << std::endl; }
        virtual double area() = 0;
        virtual ~Shape() = default;
};

class Rectangle : public Shape {
    private:
        int a;
        int b;
    public:
        Rectangle (int a, int b) : a(a), b(b) {
            std::cout << "Rectangle Construted" << std::endl;
        }
        void draw() override {std::cout << "Draw Rectangle"<< std::endl;}
        double area() override {
            return a*b;
        }
        ~Rectangle () {
            std::cout << "Rectangle Destoryed"<< std::endl;
        }
};

class Circle : public Shape {
    private:
        int r;
    public:
        Circle (int r) : r{r} {
            std::cout << "Circle Construted" << std::endl;
        }
        void draw() override {std::cout << "Draw Circle" << std::endl;}
        double area() override {
            return 2.0 * r * (22.0/7.0);
        }
        ~Circle () {
            std::cout << "Circle Destoryed" << std::endl;
        }
};


int main(int argc, char const* argv[]) {
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(2);
    circle -> draw();
    std::cout << circle -> area() << std::endl;
}   
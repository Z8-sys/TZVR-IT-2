#include "GeometricShape.h"

Circle::Circle(double r) : radius(r), GeometricShape("Circle") {
    if (r < 0) {
        std::cout << "Invalid circle" << std::endl;
        r = 0;
        //можно заменить исключением
        //throw std::invalid_argument("Invalid circle");
    }
}

Circle::Circle(const Circle& other) : GeometricShape("Circle"), radius(other.radius) {}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        radius = other.radius;
    }
    return *this;
}

Circle::~Circle() {}

double Circle::getArea() const {
    return 3.14159265358979323846 * radius * radius;
}

void Circle::printInfo() const {
    std::cout << "Circle r = " << radius << " S = " << getArea() << std::endl;
}
#include "GeometricShape.h"

Rectangle::Rectangle(double w, double h) : a(w), b(h), GeometricShape("Rectangle") {
    if (w < 0 || h < 0) {
        std::cout << "Invalid rectangle" << std::endl;
        a = 0, b = 0;
        //можно заменить исключением
        //throw std::invalid_argument("Invalid rectangle");
    }
}

Rectangle::Rectangle(const Rectangle& other) : GeometricShape("Rectangle"), a(other.a), b(other.b) { }

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
    }
    return *this;
}

Rectangle::~Rectangle() {}

double Rectangle::getArea() const {
    return a * b;
}

void Rectangle::printInfo() const {
    std::cout << "Rectangle a = " << a << " b = " << b << " S = " << getArea() << std::endl;
}
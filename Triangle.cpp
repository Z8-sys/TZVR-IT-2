#include "GeometricShape.h"

Triangle::Triangle(double sideA, double sideB, double sideC)
    : a(sideA), b(sideB), c(sideC), GeometricShape("Triangle") {
    if (!isValidTriangle()) {
        std::cout << "Invalid triangle" << std::endl;
        a = 0; b = 0; c = 0;
        //можно заменить исключением
        //throw std::invalid_argument("Invalid triangle");
    }
}

Triangle::Triangle(const Triangle& other) : GeometricShape("Triangle"), a(other.a), b(other.b), c(other.c) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

Triangle::~Triangle() { }

bool Triangle::isValidTriangle() const {
    //По правилу трех сторон
    return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
}

double Triangle::getArea() const {
    double s = (a + b + c) / 2.0;
    // Считаем площадь по формуле Герона
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::printInfo() const {
    std::cout << "Triangle a = " << a << " b = " << b << " c = " << c << " S = " << getArea() << std::endl;
}
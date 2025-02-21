#include "GeometricShape.h"

Circle::Circle(double r) : radius(r), GeometricShape("Circle") {}

Circle::Circle(const Circle& other) : GeometricShape("Circle"), radius(other.radius) {}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        radius = other.radius;
    }
    return *this;
}

Circle::~Circle() {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}
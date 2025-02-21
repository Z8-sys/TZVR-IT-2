#include "GeometricShape.h"

Rectangle::Rectangle(double w, double h) : a(w), b(h), GeometricShape("Rectangle") {}

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


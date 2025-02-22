#ifndef GEOMETRICSHAPE_H
#define GEOMETRICSHAPE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>

class GeometricShape {
protected:

    // ���������� �����������
    explicit GeometricShape(const std::string& name) : shapeName(name) {}
    // �������� ������
    const std::string shapeName;

public:
    virtual ~GeometricShape() = default; // ����������� ����������

    // ��������� ����������� � ������������
    GeometricShape(const GeometricShape&) = delete;
    GeometricShape& operator=(const GeometricShape&) = delete;

    // ����������� ����� ��� ������� �������
    virtual double getArea() const = 0;

    //����������� ����� ��� ������ ���������� � ������
    virtual void printInfo() const = 0;

    // ����� ��� ��������� �������� ������
    std::string getName() const {return shapeName;}
};


class Circle : public GeometricShape{
private:
    double radius;

public:
    // �����������
    explicit Circle(double r);

    // ����������� �����������
    Circle(const Circle& other);

    // �������� ������������
    Circle& operator=(const Circle& other);

    // ����������
    ~Circle() override;

    double getArea() const override;

    void printInfo() const override;
};

class Triangle : public GeometricShape {
private:
    double a, b, c;

public:
    // �����������
    Triangle(double sideA, double sideB, double sideC);

    // ����������� �����������
    Triangle(const Triangle& other);

    // �������� ������������
    Triangle& operator=(const Triangle& other);

    // ����������
    ~Triangle() override;

    bool isValidTriangle() const;

    double getArea() const override;

    void printInfo() const override;
};

class Rectangle : public GeometricShape {
private:
    double a, b;

public:
    // �����������
    Rectangle(double w, double h);

    // ����������� �����������
    Rectangle(const Rectangle& other);

    // �������� ������������
    Rectangle& operator=(const Rectangle& other);

    // ����������
    ~Rectangle() override;

    double getArea() const override;

    void printInfo() const override;
};

#endif // GEOMETRICSHAPE_H
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

    // Защищённый конструктор
    explicit GeometricShape(const std::string& name) : shapeName(name) {}
    // Название фигуры
    const std::string shapeName;

public:
    virtual ~GeometricShape() = default; // Виртуальный деструктор

    // Запрещаем копирование и присваивание
    GeometricShape(const GeometricShape&) = delete;
    GeometricShape& operator=(const GeometricShape&) = delete;

    // Абстрактный метод для расчета площади
    virtual double getArea() const = 0;

    //Абстрактный метод для вывода информации о фигуре
    virtual void printInfo() const = 0;

    // Метод для получения названия фигуры
    std::string getName() const {return shapeName;}
};


class Circle : public GeometricShape{
private:
    double radius;

public:
    // Конструктор
    explicit Circle(double r);

    // Конструктор копирования
    Circle(const Circle& other);

    // Оператор присваивания
    Circle& operator=(const Circle& other);

    // Деструктор
    ~Circle() override;

    double getArea() const override;

    void printInfo() const override;
};

class Triangle : public GeometricShape {
private:
    double a, b, c;

public:
    // Конструктор
    Triangle(double sideA, double sideB, double sideC);

    // Конструктор копирования
    Triangle(const Triangle& other);

    // Оператор присваивания
    Triangle& operator=(const Triangle& other);

    // Деструктор
    ~Triangle() override;

    bool isValidTriangle() const;

    double getArea() const override;

    void printInfo() const override;
};

class Rectangle : public GeometricShape {
private:
    double a, b;

public:
    // Конструктор
    Rectangle(double w, double h);

    // Конструктор копирования
    Rectangle(const Rectangle& other);

    // Оператор присваивания
    Rectangle& operator=(const Rectangle& other);

    // Деструктор
    ~Rectangle() override;

    double getArea() const override;

    void printInfo() const override;
};

#endif // GEOMETRICSHAPE_H
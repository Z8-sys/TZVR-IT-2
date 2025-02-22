#include "GeometricShape.h"

#include <cstdlib>
#include <ctime> 

static void sortShapesByArea(std::vector<GeometricShape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](const GeometricShape* a, const GeometricShape* b) {
        return a->getArea() < b->getArea();
        });
}

// Вывод информации о фигурах в консоль
static void printShapes(const std::vector<GeometricShape*>& shapes) {
    for (const auto& shape : shapes) {
        shape->printInfo();
    }
    std::cout << std::endl;
}

std::vector<GeometricShape*> generateRandomShapesAndPrint(int vectorSize) {
    std::srand(static_cast<unsigned>(std::time(0)));
    std::vector<GeometricShape*> vec;
    for (int j = 0; j < vectorSize; ++j) {
        switch (std::rand() % 3) {
        case 0: vec.push_back(new Circle(std::rand() % 10)); break;
        case 1: vec.push_back(new Triangle(3 + std::rand() % 7, 3 + std::rand() % 7, 3 + std::rand() % 7)); break;
        case 2: vec.push_back(new Rectangle(std::rand() % 10, std::rand() % 10)); break;
        }
        vec.back()->printInfo();
    }
    return vec;
}


int main() {
    std::srand(static_cast<unsigned>(std::time(0)));
    //Граничные случаи
    std::cout << "All invalid test:" << std::endl;
    std::vector<GeometricShape*> shapes = {
        new Circle(-3),
        new Triangle(10, 1, 5),
        new Rectangle(-4, -5),
        new Triangle(5, -1, 5)
    };
    printShapes(shapes);

    int n = 3; //Количество раз
    std::cout << "Random shape test sort:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Before sort:" << std::endl;
        shapes = generateRandomShapesAndPrint(7 + rand() % 10);
        sortShapesByArea(shapes);
        std::cout << "\nAfter sort:" << std::endl;
        printShapes(shapes);
    }

    // Очистка памяти
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}

/*
Пример работы
All invalid test:
Invalid circle
Invalid triangle
Invalid rectangle
Invalid triangle
Circle r = -3 S = 28.2743
Triangle a = 0 b = 0 c = 0 S = 0
Rectangle a = 0 b = 0 S = 0
Triangle a = 0 b = 0 c = 0 S = 0

Random shape test sort:
Before sort:
Circle r = 2 S = 12.5664
Circle r = 3 S = 28.2743
Circle r = 3 S = 28.2743
Triangle a = 4 b = 3 c = 3 S = 4.47214
Circle r = 8 S = 201.062
Triangle a = 6 b = 3 c = 4 S = 5.33268
Rectangle a = 9 b = 3 S = 27
Invalid triangle
Triangle a = 0 b = 0 c = 0 S = 0
Invalid triangle
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 8 b = 6 c = 9 S = 23.5253
Circle r = 1 S = 3.14159
Rectangle a = 0 b = 2 S = 0
Triangle a = 7 b = 7 c = 3 S = 10.2561
Triangle a = 3 b = 8 c = 7 S = 10.3923
Triangle a = 9 b = 8 c = 3 S = 11.8322
Rectangle a = 4 b = 2 S = 8

After sort:
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 0 b = 0 c = 0 S = 0
Rectangle a = 0 b = 2 S = 0
Circle r = 1 S = 3.14159
Triangle a = 4 b = 3 c = 3 S = 4.47214
Triangle a = 6 b = 3 c = 4 S = 5.33268
Rectangle a = 4 b = 2 S = 8
Triangle a = 7 b = 7 c = 3 S = 10.2561
Triangle a = 3 b = 8 c = 7 S = 10.3923
Triangle a = 9 b = 8 c = 3 S = 11.8322
Circle r = 2 S = 12.5664
Triangle a = 8 b = 6 c = 9 S = 23.5253
Rectangle a = 9 b = 3 S = 27
Circle r = 3 S = 28.2743
Circle r = 3 S = 28.2743
Circle r = 8 S = 201.062

Before sort:
Circle r = 2 S = 12.5664
Circle r = 3 S = 28.2743
Circle r = 3 S = 28.2743
Triangle a = 4 b = 3 c = 3 S = 4.47214
Circle r = 8 S = 201.062
Triangle a = 6 b = 3 c = 4 S = 5.33268
Rectangle a = 9 b = 3 S = 27
Invalid triangle
Triangle a = 0 b = 0 c = 0 S = 0
Invalid triangle
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 8 b = 6 c = 9 S = 23.5253
Circle r = 1 S = 3.14159
Rectangle a = 0 b = 2 S = 0
Triangle a = 7 b = 7 c = 3 S = 10.2561

After sort:
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 0 b = 0 c = 0 S = 0
Rectangle a = 0 b = 2 S = 0
Circle r = 1 S = 3.14159
Triangle a = 4 b = 3 c = 3 S = 4.47214
Triangle a = 6 b = 3 c = 4 S = 5.33268
Triangle a = 7 b = 7 c = 3 S = 10.2561
Circle r = 2 S = 12.5664
Triangle a = 8 b = 6 c = 9 S = 23.5253
Rectangle a = 9 b = 3 S = 27
Circle r = 3 S = 28.2743
Circle r = 3 S = 28.2743
Circle r = 8 S = 201.062

Before sort:
Circle r = 2 S = 12.5664
Circle r = 3 S = 28.2743
Circle r = 3 S = 28.2743
Triangle a = 4 b = 3 c = 3 S = 4.47214
Circle r = 8 S = 201.062
Triangle a = 6 b = 3 c = 4 S = 5.33268
Rectangle a = 9 b = 3 S = 27
Invalid triangle
Triangle a = 0 b = 0 c = 0 S = 0
Invalid triangle
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 8 b = 6 c = 9 S = 23.5253

After sort:
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 0 b = 0 c = 0 S = 0
Triangle a = 4 b = 3 c = 3 S = 4.47214
Triangle a = 6 b = 3 c = 4 S = 5.33268
Circle r = 2 S = 12.5664
Triangle a = 8 b = 6 c = 9 S = 23.5253
Rectangle a = 9 b = 3 S = 27
Circle r = 3 S = 28.2743
Circle r = 3 S = 28.2743
Circle r = 8 S = 201.062

*/
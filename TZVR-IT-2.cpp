#include "GeometricShape.h"

static void sortShapesByArea(std::vector<GeometricShape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](const GeometricShape* a, const GeometricShape* b) {
        return a->getArea() < b->getArea();
        });
}

// Вывод информации о фигурах в консоль
static void printShapes(const std::vector<GeometricShape*>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << shape->getName() <<" S = " << shape->getArea() << std::endl;
    }
}


int main() {
    std::vector<GeometricShape*> shapes = {
        new Circle(3),
        new Triangle(3, 4, 5),
        new Rectangle(4, 5),
        new Rectangle(6, 2)
    };

    std::cout << "Before sort:" << std::endl;
    printShapes(shapes);

    sortShapesByArea(shapes);

    std::cout << "After sort:" << std::endl;
    printShapes(shapes);

    // Очистка памяти
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include "point1.h"
#include <cmath>

// Конструктор по умолчанию
Point1::Point1() : x(0.0), y(0.0) {}

// Конструктор с параметрами
Point1::Point1(double x, double y) : x(x), y(y) {}

// Конструктор копирования
Point1::Point1(const Point1& other) : x(other.x), y(other.y) {}

// Геттеры
double Point1::getX() const { return x; }
double Point1::getY() const { return y; }

// Сеттеры
void Point1::setX(double x) { this->x = x; }
void Point1::setY(double y) { this->y = y; }

// Метод вычисления расстояния до начала координат
double Point1::distanceToOrigin() const {
    return std::sqrt(x * x + y * y);
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Point1& point) {
    os << "Point(" << point.x << ", " << point.y << ")";
    return os;
}
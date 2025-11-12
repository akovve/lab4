#include "point2.h"
#include <cmath>

// Конструктор по умолчанию
Point2::Point2() : x(0.0), y(0.0) {}

// Конструктор с параметрами
Point2::Point2(double x, double y) : x(x), y(y) {}

// Конструктор копирования
Point2::Point2(const Point2& other) : x(other.x), y(other.y) {}

// Геттеры
double Point2::getX() const { return x; }
double Point2::getY() const { return y; }

// Сеттеры
void Point2::setX(double x) { this->x = x; }
void Point2::setY(double y) { this->y = y; }

// Метод вычисления расстояния до начала координат
double Point2::distanceToOrigin() const {
    return std::sqrt(x * x + y * y);
}

// Префиксный -- (уменьшить координаты x и y на 1)
Point2& Point2::operator--() {
    --x;
    --y;
    return *this;
}

// Постфиксный -- (уменьшить координаты x и y на 1)
Point2 Point2::operator--(int) {
    Point2 temp(*this);
    --x;
    --y;
    return temp;
}

// Унарный - (поменять координаты х и у местами)
Point2 Point2::operator-() {
    return Point2(y, x);
}

// Неявное приведение к int (целая часть координаты x)
Point2::operator int() const {
    return static_cast<int>(x);
}

// Явное приведение к double (координата y)
Point2::operator double() const {
    return y;
}

// Бинарный - с целым числом (уменьшается координата х)
Point2 Point2::operator-(int value) const {
    return Point2(x - value, y);
}

// Бинарный - с Point (вычисляется расстояние до точки)
double Point2::operator-(const Point2& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Point2& point) {
    os << "Point2(" << point.x << ", " << point.y << ")";
    return os;
}
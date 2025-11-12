#ifndef POINT2_H
#define POINT2_H

#include <iostream>

class Point2 {
private:
    double x;
    double y;

public:
    // Конструкторы
    Point2();
    Point2(double x, double y);
    Point2(const Point2& other);

    // Геттеры
    double getX() const;
    double getY() const;

    // Сеттеры
    void setX(double x);
    void setY(double y);

    // Метод вычисления расстояния до начала координат
    double distanceToOrigin() const;

    // Унарные операции
    Point2& operator--();    // Префиксный --
    Point2 operator--(int);  // Постфиксный --
    Point2 operator-();      // Поменять координаты местами

    // Операции приведения типа
    operator int() const;    // Неявное приведение к int
    explicit operator double() const; // Явное приведение к double

    // Бинарные операции
    Point2 operator-(int value) const; // Вычитание целого числа
    double operator-(const Point2& other) const; // Расстояние до другой точки

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Point2& point);
};

#endif
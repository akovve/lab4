#ifndef POINT1_H
#define POINT1_H

#include <iostream>

class Point1 {
private:
    double x;
    double y;

public:
    // Конструкторы
    Point1();
    Point1(double x_val, double y_val);
    Point1(const Point1& other);

    // Геттеры
    double getX() const;
    double getY() const;

    // Сеттеры
    void setX(double x_val);
    void setY(double y_val);

    // Метод вычисления расстояния до начала координат
    double distanceToOrigin() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Point1& point);
};

#endif
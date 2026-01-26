#ifndef POINT1_H
#define POINT1_H

#include <iostream>

class Point {
public:
    Point();
    Point(double x, double y);
    Point(const Point& other);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    double distanceToOrigin() const;

    Point& operator--(); 
    Point operator--(int);
    Point operator-() const;

    operator int() const;         
    explicit operator double() const;

    Point operator-(int value) const;
    double operator-(const Point& other) const; 

    friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
    double x_;
    double y_;
};

#endif

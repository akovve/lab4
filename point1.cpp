#include "point1.h"
#include <cmath>

Point::Point() : x_(0.0), y_(0.0) {}

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

double Point::getX() const { return x_; }
double Point::getY() const { return y_; }

void Point::setX(double x) { x_ = x; }
void Point::setY(double y) { y_ = y; }

double Point::distanceToOrigin() const {
    return std::sqrt(x_ * x_ + y_ * y_);
}

Point& Point::operator--() {
    --x_;
    --y_;
    return *this;
}

Point Point::operator--(int) {
    Point temp(*this);
    --x_;
    --y_;
    return temp;
}

Point Point::operator-() const {
    return Point(y_, x_);
}

Point::operator int() const {
    return static_cast<int>(x_);
}

Point::operator double() const {
    return y_;
}

Point Point::operator-(int value) const {
    return Point(x_ - value, y_);
}

double Point::operator-(const Point& other) const {
    return std::sqrt((x_ - other.x_) * (x_ - other.x_) + (y_ - other.y_) * (y_ - other.y_));
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "Point(" << point.x_ << ", " << point.y_ << ")";
    return os;
}

}


#include "point.h"
#define _USE_MATH_DEFINES 
#include <math.h>
#include <compare>

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

Point::Point(const double x, const double y, const double z)
{
    set_x(x);
    set_y(y);
    set_z(z);
}


Point::Point(const Point&& point) noexcept
{
    set_x(point.x);
    set_y(point.y);
    set_z(point.z);

    //point.~Point();
}


Point& Point::operator=(Point&& point) noexcept
{
    set_x(point.x);
    set_y(point.y);
    set_z(point.z);

    //point.~Point();

    return *this;
}

Point Point::get() const { return (*this); }

double Point::get_x() const { return this->x; }

double Point::get_y() const { return this->y; }

double Point::get_z() const { return this->z; }

void Point::set_x(const double x) { this->x = x; }

void Point::set_y(const double y) { this->y = y; }

void Point::set_z(const double z) { this->z = z; }

bool Point::operator==(const Point& point) const noexcept { return (point.x == x) && (point.y == y) && (point.z == z); }

bool Point::operator!=(const Point& point) const noexcept { return !(*this == point); }

bool Point::is_equal(const Point& point) const noexcept { return (*this) == point; }

bool Point::is_not_equal(const Point& point) const noexcept { return !(*this == point); }

Point Point::operator+(const Point& point) const
{
    Point temp{ *this };

    temp.set_x(temp.x + point.x);
    temp.set_y(temp.y + point.y);
    temp.set_z(temp.z + point.z);

    return temp;
}

Point Point::operator-(const Point& point) const
{
    Point temp{ *this };

    temp.set_x(temp.x - point.x);
    temp.set_y(temp.y - point.y);
    temp.set_z(temp.z - point.z);

    return temp;
}


void Point::transform(const TransformMatrix& mtr)
{
    TransformMatrix cur_place ({ {this->x, this->y, this->z, 1} });
    TransformMatrix new_place = cur_place * mtr;

    this->x = new_place.get(0, 0);
    this->y = new_place.get(0, 1);
    this->z = new_place.get(0, 2);
}

Point Point::get_abs_point(const Point& center) { return (*this) + center; }
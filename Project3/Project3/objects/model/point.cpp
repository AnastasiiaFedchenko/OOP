#include "point.h"
#define _USE_MATH_DEFINES 
#include <math.h>
#include <compare>

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

My_Point::My_Point(const double x, const double y, const double z)
{
    set_x(x);
    set_y(y);
    set_z(z);
}


My_Point::My_Point(const My_Point&& point) noexcept
{
    set_x(point.x);
    set_y(point.y);
    set_z(point.z);

    //point.~My_Point();
}


My_Point& My_Point::operator=(My_Point&& point) noexcept
{
    set_x(point.x);
    set_y(point.y);
    set_z(point.z);

    //point.~My_Point();

    return *this;
}

My_Point My_Point::get() const { return (*this); }

double My_Point::get_x() const { return this->x; }

double My_Point::get_y() const { return this->y; }

double My_Point::get_z() const { return this->z; }

void My_Point::set_x(const double x) { this->x = x; }

void My_Point::set_y(const double y) { this->y = y; }

void My_Point::set_z(const double z) { this->z = z; }

bool My_Point::operator==(const My_Point& point) const noexcept { return (point.x == x) && (point.y == y) && (point.z == z); }

bool My_Point::operator!=(const My_Point& point) const noexcept { return !(*this == point); }

bool My_Point::is_equal(const My_Point& point) const noexcept { return (*this) == point; }

bool My_Point::is_not_equal(const My_Point& point) const noexcept { return !(*this == point); }

My_Point My_Point::operator+(const My_Point& point) const
{
    My_Point temp{ *this };

    temp.set_x(temp.x + point.x);
    temp.set_y(temp.y + point.y);
    temp.set_z(temp.z + point.z);

    return temp;
}

My_Point My_Point::operator-(const My_Point& point) const
{
    My_Point temp{ *this };

    temp.set_x(temp.x - point.x);
    temp.set_y(temp.y - point.y);
    temp.set_z(temp.z - point.z);

    return temp;
}

My_Point My_Point::get_abs_point(const My_Point& center) { return (*this) + center; }
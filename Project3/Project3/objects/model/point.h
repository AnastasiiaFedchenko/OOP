#pragma once
#include "../../matrix/transform_matrix.h"

class Point
{
public:
    Point() = default;
    Point(const double x, const double y, const double z);

    Point(const Point& p) = default;
    Point(const Point&& p) noexcept;

    Point& operator=(const Point& point) = default;
    Point& operator=(Point&& point) noexcept;

    ~Point() = default;

    Point get() const;
    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double const x);
    void set_y(double const y);
    void set_z(double const z);

    bool operator==(const Point& point) const noexcept;
    bool is_equal(const Point& point) const noexcept;

    bool operator!=(const Point& point) const noexcept;
    bool is_not_equal(const Point& point) const noexcept;

    Point operator+(const Point& point)  const;
    Point operator-(const Point& point)  const;

    Point get_abs_point(const Point& center);

    void transform(const TransformMatrix& mtr);

private:
    double x;
    double y;
    double z;
};

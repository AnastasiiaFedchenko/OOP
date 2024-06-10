#pragma once
//#include "../../matrix/transform_matrix.h"
//class Transform;

class My_Point
{
public:
    My_Point() = default;
    My_Point(const double x, const double y, const double z);

    My_Point(const My_Point& p) = default;
    My_Point(const My_Point&& p) noexcept;

    My_Point& operator=(const My_Point& point) = default;
    My_Point& operator=(My_Point&& point) noexcept;

    ~My_Point() = default;

    My_Point get() const;
    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double const x);
    void set_y(double const y);
    void set_z(double const z);

    bool operator==(const My_Point& point) const noexcept;
    bool is_equal(const My_Point& point) const noexcept;

    bool operator!=(const My_Point& point) const noexcept;
    bool is_not_equal(const My_Point& point) const noexcept;

    My_Point operator+(const My_Point& point)  const;
    My_Point operator-(const My_Point& point)  const;

    My_Point get_abs_point(const My_Point& center);

    //void transform(Transform& mtr);

private:
    double x;
    double y;
    double z;
};

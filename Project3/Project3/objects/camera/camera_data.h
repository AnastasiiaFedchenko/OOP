#pragma once
#include "../model/point.h"

class CameraData
{
public:
    CameraData() = default;
    CameraData(const Point& location, const Point& direction) : location(location), direction(direction)
    { }
    ~CameraData() = default;

    Point& get_location();
    Point& get_direction();

    void set_location(Point& p);
    void set_direction(Point& p);

private:
    Point location;
    Point direction;
};
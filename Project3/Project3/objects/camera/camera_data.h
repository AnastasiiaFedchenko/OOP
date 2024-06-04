#pragma once
#include "../model/point.h"

class CameraData
{
public:
    CameraData() = default;
    CameraData(const My_Point& location, const My_Point& direction) : location(location), direction(direction)
    { }
    ~CameraData() = default;

    My_Point& get_location();
    My_Point& get_direction();

    void set_location(My_Point& p);
    void set_direction(My_Point& p);

private:
    My_Point location;
    My_Point direction;
};
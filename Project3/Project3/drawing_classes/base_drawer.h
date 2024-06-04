#pragma once
#include "../objects/model/point.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void draw_line(My_Point p1, My_Point p2) = 0;
    virtual void clear_scene() = 0;
};
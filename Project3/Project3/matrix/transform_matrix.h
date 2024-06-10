#pragma once
#include <utility>
#include <vector>
#include "../objects/model/point.h"
//class My_Point;

class Transform
{
public:
    Transform() = default;
    Transform(const Transform& temp) = default;

    Transform& operator=(const Transform& temp);
    Transform& operator=(Transform&& temp);

    void imply(My_Point& p);

    ~Transform() = default;

protected:
    static std::vector<std::vector<double>> mul (const std::vector<std::vector<double>>& temp1,
                                          const std::vector<std::vector<double>>& temp2);
    std::vector<std::vector<double>> matrix;
};

class TransformRotate : public Transform
{
public:
    TransformRotate(const double ang_x, const double ang_y, const double ang_z)
    {
        std::vector<std::vector<double>> mtr_ox;
        mtr_ox = { {1, 0, 0, 0},
                    {0, cos(ang_x), -sin(ang_x), 0},
                    {0, sin(ang_x),  cos(ang_x), 0},
                    {0, 0, 0, 1} };
        std::vector<std::vector<double>> mtr_oy;
        mtr_oy = { {cos(ang_y), 0, sin(ang_y), 0},
                   {0, 1, 0, 0},
                   {-sin(ang_y), 0, cos(ang_y), 0},
                   {0, 0, 0, 1} };
        std::vector<std::vector<double>> mtr_oz;
        mtr_oz = { {cos(ang_z), -sin(ang_z), 0, 0},
                   {sin(ang_z), cos(ang_z), 0, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 1} };

        matrix = mul(mul(mtr_ox, mtr_oy), mtr_oz);
    }

    ~TransformRotate() = default;
};

class TransformScale : public Transform
{
public:
    TransformScale(const double kx, const double ky, const double kz)
    {
        matrix = { { kx, 0, 0, 0 },
                   { 0, ky, 0, 0 },
                   { 0, 0, kz, 0 },
                   { 0, 0, 0, 1 } };
    }

    ~TransformScale() = default;
};

class TransformShift : public Transform
{
public:
    TransformShift(const double dx, const double dy, const double dz)
    {
        matrix = { { 1, 0, 0, 0 },
                   { 0, 1, 0, 0 },
                   { 0, 0, 1, 0 },
                   { dx, dy, dz, 1 } };
    }

    ~TransformShift() = default;
};


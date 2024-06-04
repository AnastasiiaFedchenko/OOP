#pragma once
#include "../base_object.h"
#include "../../matrix/transform_matrix.h"
#include "../model/point.h"
#include "camera_data.h"

class Camera: public BaseObject
{
public:
    Camera() : data(new CameraData) { }
    explicit Camera(const std::shared_ptr<CameraData>& data) : data(data) { }
    ~Camera() override = default;

    virtual My_Point get_center() const override;
    void transform(const TransformMatrix& mtr, const My_Point& center) override;
    My_Point get_projection(const My_Point& point);
private:
    std::shared_ptr<CameraData> data;
};
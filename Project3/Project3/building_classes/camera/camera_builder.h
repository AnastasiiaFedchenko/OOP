#pragma once
#include "../../objects/camera/camera.h"
#include "../../objects/camera/camera_data.h"
#include "base_camera_builder.h"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    void build() override;
    void build_location(const Point& location, const Point& direction) override;
    bool is_build() const override;

    std::shared_ptr<Camera> get() override;
};


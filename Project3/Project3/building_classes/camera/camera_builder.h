#pragma once
#include "../../objects/camera/camera.h"
#include "../../objects/camera/camera_data.h"
#include "base_camera_builder.h"
#include "../reader/file_reader.h"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder(std::shared_ptr<FileReader> reader);
    ~CameraBuilder() = default;

    void build() override;
    bool build_location() override;
    bool build_direction() override;
    bool is_build() const override;

    std::shared_ptr<Camera> get() override;
private:
    My_Point location;
    My_Point direction;
    std::shared_ptr<FileReader> reader;
};


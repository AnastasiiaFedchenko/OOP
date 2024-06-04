#pragma once
#include "../base_builder.h"
#include <memory>

#include "../../objects/camera/camera.h"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual void build() override = 0;
    virtual bool build_location() = 0;
    virtual bool build_direction() = 0;
    virtual bool is_build() const override = 0;

    virtual std::shared_ptr<Camera> get() = 0;

protected:
    std::shared_ptr<Camera> camera;
};
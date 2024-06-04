#include "camera_director.h"


CameraDirector::CameraDirector() {}

CameraDirector::CameraDirector(std::shared_ptr<CameraBuilder> builder)
{
    this->builder = builder;
}

std::shared_ptr<BaseObject> CameraDirector::create()
{
    builder->build_location();
    builder->build_direction();
    builder->build();
    return builder->get();
}

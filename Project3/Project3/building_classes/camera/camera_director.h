#pragma once
#include "../base_director.h"
#include "camera_builder.h"

class CameraDirector : public BaseDirector
{
public:
    CameraDirector();
    CameraDirector(std::shared_ptr<CameraBuilder> builder);

    std::shared_ptr<BaseObject> create() override;
private:
    std::shared_ptr<CameraBuilder> builder;
};

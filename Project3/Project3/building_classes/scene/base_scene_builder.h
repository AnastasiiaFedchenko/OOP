#pragma once
#include "../../objects/scene/scene.h"
#include "../../objects/base_object.h"
#include "../base_builder.h"
#include <memory>

class BaseSceneBuilder : public BaseBuilder
{
public:
    BaseSceneBuilder() = default;
    ~BaseSceneBuilder() = default;

    virtual void build() override = 0;
    virtual void buildObject(const std::shared_ptr<BaseObject>& object) = 0;
    virtual bool is_build() const override = 0;

    virtual std::shared_ptr<Scene> get() = 0;

protected:
    std::shared_ptr<Scene> _scene;
};

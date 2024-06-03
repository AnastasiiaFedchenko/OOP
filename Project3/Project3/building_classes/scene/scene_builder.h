#pragma once
#include "base_scene_builder.h"

class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    void build() override;
    void buildObject(const std::shared_ptr<BaseObject>& object) override;
    bool is_build() const override;

    std::shared_ptr<Scene> get() override;

private:
    std::shared_ptr<Scene> scene;
};


#pragma once
#include "base_scene_builder.h"

class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    void build() override;
    void build_model(const std::shared_ptr<BaseModel>& model) override;
    void build_camera(const std::shared_ptr<Camera>& camera) override;
    bool is_build() const override;

    std::shared_ptr<Scene> get() override;

private:
    std::shared_ptr<Scene> scene;
};


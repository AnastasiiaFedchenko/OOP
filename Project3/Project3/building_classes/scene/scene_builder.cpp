#include "scene_builder.h"


void SceneBuilder::build() { scene = std::make_shared<Scene>(); }


void SceneBuilder::build_model(const std::shared_ptr<BaseModel>& model) { scene->add_model(model); }

void SceneBuilder::build_camera(const std::shared_ptr<Camera>& camera) { scene->add_camera(camera); }

bool SceneBuilder::is_build() const { return nullptr != scene; }


std::shared_ptr<Scene> SceneBuilder::get() { return scene; }
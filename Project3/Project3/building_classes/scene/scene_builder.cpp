#include "scene_builder.h"


void SceneBuilder::build() { scene = std::make_shared<Scene>(); }

void SceneBuilder::build_object(const std::shared_ptr<BaseObject>& obj) { scene->add_object(obj); }

bool SceneBuilder::is_build() const { return nullptr != scene; }


std::shared_ptr<Scene> SceneBuilder::get() { return scene; }
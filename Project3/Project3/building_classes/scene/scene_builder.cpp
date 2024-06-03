#include "scene_builder.h"


void SceneBuilder::build() { scene = std::make_shared<Scene>(); }


void SceneBuilder::buildObject(const std::shared_ptr<BaseObject>& object) { scene->add_object(object); }


bool SceneBuilder::is_build() const { return nullptr != scene; }


std::shared_ptr<Scene> SceneBuilder::get() { return scene; }
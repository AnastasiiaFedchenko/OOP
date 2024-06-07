#include "scene.h"

Scene::Scene() : models(new Composite), cameras(new Composite) { }

std::size_t Scene::add_object(const std::shared_ptr<BaseObject>& object)
{
    if (object->is_visible())
    {
        models->add(object);
    }
    else
    {
        cameras->add(object);
    }
    return object->get_id();
}

std::size_t Scene::add_model(const std::shared_ptr<BaseModel>& model)
{
    models->add(model);

    return model->get_id();
}

std::size_t Scene::add_camera(const std::shared_ptr<Camera>& camera)
{
    cameras->add(camera);

    return camera->get_id();
}

void Scene::delete_object(const std::size_t& id_object)
{
    if (models->remove(id_object) == false)
        cameras->remove(id_object);
}

void Scene::delete_model(const std::size_t &id_model)
{
    models->remove(id_model);
}

void Scene::delete_camera(const std::size_t& id_camera)
{
    cameras->remove(id_camera);
}

std::shared_ptr<BaseObject> Scene::get_model(const std::size_t& id_model)
{
    return models->get(id_model);
}

std::shared_ptr<BaseObject> Scene::get_camera(const std::size_t& id_camera)
{
    return cameras->get(id_camera);
}

//std::shared_ptr<BaseObject> Scene::get_object(const std::size_t id) { return *get_object_iter(id); }

std::shared_ptr<Composite> Scene::get_models() { return models; }

std::shared_ptr<Composite> Scene::get_cameras() { return cameras; }

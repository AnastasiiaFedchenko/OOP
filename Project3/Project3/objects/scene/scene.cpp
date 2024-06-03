#include "scene.h"

Scene::Scene() : models(new Composite), cameras(new Composite) { }

std::size_t Scene::add_object(const std::shared_ptr<BaseObject>& object)
{
    if (object->is_visible())
        models->add(object);
    else
        cameras->add(object);

    return object->get_id();
}

std::size_t Scene::add_camera(const Point& location, const Point& direction)
{
    auto camera = std::make_shared<Camera>(std::make_shared<CameraData>(location, direction));
    cameras->add(camera);

    return camera->get_id();
}

void Scene::delete_object(Iterator& iter)
{
    if ((*iter)->is_visible())
        models->remove(iter);
    else
        cameras->remove(iter);
}

Iterator Scene::get_object_iter(const std::size_t id)
{
    auto iter = begin_m();
    for (; iter != end_m() && (*iter)->get_id() != id; ++iter);

    if (iter == end_m())
    {
        iter = begin_c();
        for (; iter != end_c() && (*iter)->get_id() != id; ++iter);
    }

    return iter;
}

std::shared_ptr<BaseObject> Scene::get_object(const std::size_t id) { return *get_object_iter(id); }

std::shared_ptr<Composite> Scene::get_models() { return models; }

std::shared_ptr<Composite> Scene::get_cameras() { return cameras; }

Iterator Scene::begin_m() { return models->begin(); }

Iterator Scene::end_m() { return models->end(); }

Iterator Scene::begin_c() { return cameras->begin(); }

Iterator Scene::end_c() { return cameras->end(); }
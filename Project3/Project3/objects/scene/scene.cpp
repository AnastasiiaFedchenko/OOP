#include "scene.h"

Scene::Scene() : objects(std::map<std::size_t, std::shared_ptr<BaseObject>>()) { }

std::size_t Scene::add_object(const std::shared_ptr<BaseObject>& object)
{
    objects[object->get_id()] = object;
    return object->get_id();
}

void Scene::delete_object(const std::size_t& id_object)
{
    if (objects.count(id_object) == 0)
    {
        throw LoadException((std::string)"No object with such id");
        return;
    }
    objects.erase(id_object);
}

std::shared_ptr<BaseObject> Scene::get_object(const std::size_t& id)
{
    return objects[id];
}

Scene::iterator Scene::begin()
{
    return objects.begin();
}
Scene::iterator Scene::end()
{
    return objects.end();
}
Scene::const_iterator Scene::cbegin()
{
    return objects.cbegin();
}
Scene::const_iterator Scene::cend()
{
    return objects.cend();
}

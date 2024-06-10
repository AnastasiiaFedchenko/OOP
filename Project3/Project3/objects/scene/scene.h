#pragma once
#include <memory>
#include <vector>

#include "../../exceptions.h"
#include "../base_object.h"
#include "../camera/camera.h"
//#include "../composite/composite.h"
#include "../model/base_model.h"
#include <map>

class Scene
{
public:
    using value_type = std::shared_ptr<BaseObject>;
    using iterator = std::map<std::size_t, std::shared_ptr<BaseObject>>::iterator;
    using const_iterator = std::map<std::size_t, std::shared_ptr<BaseObject>>::const_iterator;
    using size_type = std::map<std::size_t, std::shared_ptr<BaseObject>>::size_type;

    Scene();
    ~Scene() = default;

    std::size_t add_object(const std::shared_ptr<BaseObject>& object);
    void delete_object(const std::size_t& id_object);
    std::shared_ptr<BaseObject> get_object(const std::size_t& id);

    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();

protected:
    std::map<std::size_t, std::shared_ptr<BaseObject>> objects;
};

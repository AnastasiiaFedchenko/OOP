#pragma once
#include <memory>
#include <vector>

#include "../base_object.h"
#include "../camera/camera.h"
#include "../composite/composite.h"
#include "../model/base_model.h"

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class Scene
{
public:
    Scene();
    ~Scene() = default;

    //std::size_t add_object(const std::shared_ptr<BaseObject>& object); // return object id
    std::size_t add_object(const std::shared_ptr<BaseObject>& object);
    std::size_t add_model(const std::shared_ptr<BaseModel>& model); // return model id
    std::size_t add_camera(const std::shared_ptr<Camera>& camera);  // return camera id
    void delete_object(const std::size_t& id_object);
    void delete_model(const std::size_t& id_model);
    void delete_camera(const std::size_t& id_camera);

    //Iterator get_object_iter(const std::size_t id);
    std::shared_ptr<BaseObject> get_model(const std::size_t& id_model);
    std::shared_ptr<BaseObject> get_camera(const std::size_t& id_camera);
    std::shared_ptr<Composite> get_models();
    std::shared_ptr<Composite> get_cameras();

    /*Iterator begin_m();
    Iterator end_m();

    Iterator begin_c();
    Iterator end_c();*/

protected:
    std::shared_ptr<Composite> models;
    std::shared_ptr<Composite> cameras;
};

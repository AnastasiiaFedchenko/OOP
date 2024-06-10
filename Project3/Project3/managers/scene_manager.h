#pragma once
#include <memory>
#include "base_managers.h"
#include "../objects/camera/camera.h"
#include "../objects/scene/scene.h"

class SceneManager : public BaseSceneManager
{
public:
    SceneManager()
    {
        main_camera = nullptr;
        scene = std::make_shared<Scene>(Scene());
    }
    ~SceneManager() = default;

    void set_main_camera(const std::size_t cam_id)
    {
        std::shared_ptr<BaseObject> cam = scene->get_object(cam_id);
        auto cam_pnt = std::dynamic_pointer_cast<Camera>(cam);
        main_camera = cam_pnt;
    }
    void set_scene(std::shared_ptr<Scene> scene) { scene = scene; }
    std::shared_ptr<Camera> get_main_camera() { return main_camera; }
    std::shared_ptr<Scene> get_scene() { return scene; }

    std::size_t add_object(std::shared_ptr<BaseObject>& object) { return scene->add_object(object); }
    void delete_object(const std::size_t& id_object) { scene->delete_object(id_object); }

    void shift_objects(std::vector<std::size_t>& objects,
        const double dx, const double dy, const double dz)
    {
        TransformShift mtr(dx, dy, dz);
        for (auto& id : objects)
        {
            std::shared_ptr<BaseObject> obj = scene->get_object(id);
            obj->transform(mtr, obj->get_center());
        }
    }
    void scale_objects(std::vector<std::size_t>& objects,
        const double kx, const double ky, const double kz)
    {
        TransformScale mtr(kx, ky, kz);
        for (auto& id : objects)
        {
            std::shared_ptr<BaseObject> obj = scene->get_object(id);
            obj->transform(mtr, obj->get_center());
        }
    }
    void rotate_objects(std::vector<std::size_t>& objects,
        const double ang_x, const double ang_y, const double ang_z)
    {
        TransformRotate mtr(ang_x, ang_y, ang_z);
        for (auto& id : objects)
        {
            std::shared_ptr<BaseObject> obj = scene->get_object(id);
            obj->transform(mtr, obj->get_center());
        }
    }

private:
    std::shared_ptr<Camera> main_camera;
    std::shared_ptr<Scene> scene;
};

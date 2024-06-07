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
        camera = nullptr;
        scene = std::make_shared<Scene>(Scene());
    }
    ~SceneManager() = default;

    void set_main_camera(const std::size_t cam_id)
    {
        std::shared_ptr<BaseObject> cam = scene->get_camera(cam_id);
        auto cam_pnt = std::dynamic_pointer_cast<Camera>(cam);
        camera = cam_pnt;
    }
    void set_scene(std::shared_ptr<Scene> scene) { scene = scene; }
    std::shared_ptr<Camera> get_main_camera() { return camera; }
    std::shared_ptr<Scene> get_scene() { return scene; }

    std::size_t add_object(std::shared_ptr<BaseObject>& object) { return scene->add_object(object); }
    std::size_t add_model(std::shared_ptr<BaseModel>& object) { return scene->add_model(object); }
    std::size_t add_camera(std::shared_ptr<Camera>& object) { return scene->add_camera(object); }

    void delete_object(const std::size_t& id_object) { scene->delete_object(id_object); }
    void delete_model(const std::size_t& id_object) { scene->delete_model(id_object); }
    void delete_camera(const std::size_t& id_camera)
    {
        if (camera->get_id() == id_camera)
            camera = nullptr;
        scene->delete_camera(id_camera);
    }
    void move_objects(std::vector<std::size_t>& models, std::vector<std::size_t>& cameras,
        const double dx, const double dy, const double dz)
    {
        TransformMatrix mtr{};
        mtr = { { 1, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 0, 1, 0 },
                { dx, dy, dz, 1 } };
        for (auto& id : models)
        {
            std::shared_ptr<BaseObject> obj = scene->get_model(id);
            obj->transform(mtr, obj->get_center());
            // obj->move(dx, dy, dz);
        }

        for (auto& id : cameras)
        {
            std::shared_ptr<BaseObject> obj = scene->get_camera(id);
            obj->transform(mtr, obj->get_center());
        }
    }
    void scale_objects(std::vector<std::size_t>& models, std::vector<std::size_t>& cameras,
        const double kx, const double ky, const double kz)
    {
        TransformMatrix mtr{};
        mtr = { { kx, 0, 0, 0 },
                { 0, ky, 0, 0 },
                { 0, 0, kz, 0 },
                { 0, 0, 0, 1 } };
        for (auto& id : models)
        {
            std::shared_ptr<BaseObject> obj = scene->get_model(id);
            obj->transform(mtr, obj->get_center());
        }

        for (auto& id : cameras)
        {
            std::shared_ptr<BaseObject> obj = scene->get_camera(id);
            obj->transform(mtr, obj->get_center());
        }
    }
    void rotate_objects(std::vector<std::size_t>& models, std::vector<std::size_t>& cameras,
        const double ang_x, const double ang_y, const double ang_z)
    {
        TransformMatrix mtr_ox{};
        mtr_ox = { {1, 0, 0, 0},
                   {0, cos(ang_x), -sin(ang_x), 0},
                   {0, sin(ang_x),  cos(ang_x), 0},
                   {0, 0, 0, 1} };
        TransformMatrix mtr_oy{};
        mtr_oy = { {cos(ang_y), 0, sin(ang_y), 0},
                   {0, 1, 0, 0},
                   {-sin(ang_y), 0, cos(ang_y), 0},
                   {0, 0, 0, 1} };
        TransformMatrix mtr_oz{};
        mtr_oz = { {cos(ang_z), -sin(ang_z), 0, 0},
                   {sin(ang_z), cos(ang_z), 0, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 1} };
        TransformMatrix mtr{};
        mtr = mtr_ox * mtr_oy * mtr_oz;
        for (auto& id : models)
        {
            std::shared_ptr<BaseObject> obj = scene->get_model(id);
            obj->transform(mtr, obj->get_center());
        }

        for (auto& id : cameras)
        {
            std::shared_ptr<BaseObject> obj = scene->get_camera(id);
            obj->transform(mtr_ox * mtr_oy * mtr_oz, obj->get_center());
        }
    }

private:
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Scene> scene;
};

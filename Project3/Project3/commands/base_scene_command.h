#pragma once
#include "base_command.h"

class BaseSceneCommand : public BaseCommand {};

class ShiftCommand : public BaseSceneCommand
{
    using Action = void(SceneManager::*)(std::vector<std::size_t>& objects,
        const double dx, const double dy, const double dz);

public:
    ShiftCommand(std::vector<std::size_t>& objects,
        const double dx, const double dy, const double dz)
    {
        this->objects = objects;
        this->dx = dx;
        this->dy = dy;
        this->dz = dz;
        method = &SceneManager::shift_objects;
    }
    virtual void execute() override
    {
        ((*scene_manager).*method)(objects, dx, dy, dz);
    }

private:
    std::vector<std::size_t> objects;
    double dx, dy, dz;
    Action method;
};

class ScaleCommand : public BaseSceneCommand
{
    using Action = void(SceneManager::*)(std::vector<std::size_t>& objects,
        const double kx, const double ky, const double kz);

public:
    ScaleCommand(std::vector<std::size_t>& objects,
        const double kx, const double ky, const double kz)
    {
        this->objects = objects;
        this->kx = kx;
        this->ky = ky;
        this->kz = kz;
        method = &SceneManager::scale_objects;
    }
    virtual void execute() override
    {
        ((*scene_manager).*method)(objects, kx, ky, kz);
    }

private:
    std::vector<std::size_t> objects;
    double kx, ky, kz;
    Action method;
};

class RotateCommand : public BaseSceneCommand
{
    using Action = void(SceneManager::*)(std::vector<std::size_t>& objects,
        const double ang_x, const double ang_y, const double ang_z);

public:
    RotateCommand(std::vector<std::size_t>& objects,
        const double ang_x, const double ang_y, const double ang_z)
    {
        this->objects = objects;
        this->ang_x = ang_x;
        this->ang_y = ang_y;
        this->ang_z = ang_z;
        method = &SceneManager::rotate_objects;
    }
    virtual void execute() override
    {
        ((*scene_manager).*method)(objects, ang_x, ang_y, ang_z);
    }

private:
    std::vector<std::size_t> objects;
    double ang_x, ang_y, ang_z;
    Action method;
};

class AddObjectCommand : public BaseSceneCommand
{
    using Action = std::size_t(SceneManager::*)(std::shared_ptr<BaseObject>& object);

public:
    AddObjectCommand(std::shared_ptr<BaseObject> object, std::shared_ptr<std::size_t> id) : id(id)
    {
        this->object = object;
        method = &SceneManager::add_object;
    }
    virtual void execute() override
    {
        (*id) = ((*scene_manager).*method)(object);
    }

private:
    std::shared_ptr<BaseObject> object;
    std::shared_ptr<std::size_t> &id;
    Action method;
};

class DeleteObjectCommand : public BaseSceneCommand
{
    using Action = void(SceneManager::*)(const std::size_t& id_object);

public:
    DeleteObjectCommand(const std::size_t& id_object)
    {
        this->id_object = id_object;
        method = &SceneManager::delete_object;
    }
    virtual void execute() override
    {
        ((*scene_manager).*method)(id_object);
    }

private:
    std::size_t id_object;
    Action method;
};

class GetMainCameraCommand : public BaseSceneCommand
{
    using Action = std::shared_ptr<Camera>(SceneManager::*)();

public:
    GetMainCameraCommand(std::shared_ptr<Camera>& camera) : camera(camera)
    {
        method = &SceneManager::get_main_camera;
    }
    virtual void execute() override
    {
        camera = ((*scene_manager).*method)();
    }

private:
    std::shared_ptr<Camera> &camera;
    Action method;
};

class SetMainCameraCommand : public BaseSceneCommand
{
    using Action = void(SceneManager::*)(const std::size_t id_camera);

public:
    SetMainCameraCommand(const std::size_t& id_camera)
    {
        this->id_camera = id_camera;
        method = &SceneManager::set_main_camera;
    }
    virtual void execute() override
    {
        ((*scene_manager).*method)(id_camera);
    }

private:
    std::size_t id_camera;
    Action method;
};

class GetSceneCommand : public BaseSceneCommand
{
    using Action = std::shared_ptr<Scene>(SceneManager::*)();

public:
    GetSceneCommand(std::shared_ptr<Scene>& scene) : scene(scene)
    {
        this->scene = scene;
        method = &SceneManager::get_scene;
    }
    virtual void execute() override
    {
        scene = ((*scene_manager).*method)();
    }

private:
    std::shared_ptr<Scene> &scene;
    Action method;
};

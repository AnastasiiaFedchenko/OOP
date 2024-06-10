#pragma once

#include "base_command.h"
//#include "../objects/camera/camera.h"
#include <iostream>

class BaseDrawCommand : public BaseCommand {};

class DrawSceneCommand : public BaseDrawCommand
{
    using Action = void(DrawManager::*)(std::shared_ptr<Scene> scene);

public:
    DrawSceneCommand(std::shared_ptr<Scene> scene)
    {
        this->scene = scene;
        method = &DrawManager::draw_scene;
    }
    virtual void execute() override
    {
        ((*draw_manager).*method)(scene);
    }

private:
    Action method;
    std::shared_ptr<Scene> scene;
};

class ClearSceneCommand : public BaseDrawCommand
{
    using Action = void(DrawManager::*)();

public:
    ClearSceneCommand()
    {
        method = &DrawManager::clear_scene;
    }
    virtual void execute() override
    {
        ((*draw_manager).*method)();
    }

private:
    Action method;
};

class SetNewDrawingCameraCommand : public BaseDrawCommand
{
    using Action = void(DrawManager::*)(std::shared_ptr<Camera> camera);

public:
    SetNewDrawingCameraCommand(std::shared_ptr<Camera> camera)
    {
        this->camera = camera;
        method = &DrawManager::set_camera;
    }
    virtual void execute() override
    {
        ((*draw_manager).*method)(camera);
    }

private:
    Action method;
    std::shared_ptr<Camera> camera;
};
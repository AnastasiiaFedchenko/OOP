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
    ClearSceneCommand(std::shared_ptr<BaseDrawer> drawer)
    {
        this->drawer = drawer;
        method = &DrawManager::clear_scene;
    }
    virtual void execute() override
    {
        ((*draw_manager).*method)();
    }

private:
    std::shared_ptr<BaseDrawer> drawer;
    Action method;
};

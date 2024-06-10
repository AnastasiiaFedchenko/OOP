#pragma once
#include <memory>
#include "managers/draw_manager.h"
#include "managers/scene_manager.h"
#include "managers/load_manager.h"
#include "commands/base_command.h"

class Facade
{
public:
    Facade() = default;
    Facade(std::shared_ptr<DrawVisitor> v)
    {
        draw_manager = std::make_shared<DrawManager>(DrawManager(v));
        scene_manager = std::make_shared<SceneManager>(SceneManager());
        load_manager = std::make_shared<FileLoadManager>(FileLoadManager());
    }
    ~Facade() = default;

    void execute(BaseCommand& command)
    {
        command.set_managers(draw_manager, scene_manager, load_manager);
        command.execute();
    }

private:
    std::shared_ptr<DrawManager> draw_manager;
    std::shared_ptr<FileLoadManager> load_manager;
    std::shared_ptr<SceneManager> scene_manager;
};


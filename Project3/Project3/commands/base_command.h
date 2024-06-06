#pragma once
#include <memory>
#include "../managers/draw_manager.h"
#include "../managers/load_manager.h"
#include "../managers/scene_manager.h"

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void set_managers(std::shared_ptr<DrawManager> draw_manager,
        std::shared_ptr<SceneManager> scene_manager,
        std::shared_ptr<FileLoadManager> load_manager)
    {
        this->draw_manager = draw_manager;
        this->scene_manager = scene_manager;
        this->load_manager = load_manager;
    }

    virtual void execute() = 0;

protected:
    std::shared_ptr<DrawManager> draw_manager;
    std::shared_ptr<SceneManager> scene_manager;
    std::shared_ptr<FileLoadManager> load_manager;
};

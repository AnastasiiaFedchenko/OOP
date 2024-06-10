#pragma once
#include <memory>
#include "base_managers.h"
#include "../objects/scene/scene.h"
#include "../objects/model/carcas_model.h"
#include "../drawing_classes/base_drawer.h"
#include "../drawing_classes/drawer_solution.h"
#include "../drawing_classes/abstract_factory.h"


class DrawManager : BaseDrawManager
{
public:
    DrawManager(std::shared_ptr<DrawVisitor> v)
    {
        this->v = v;
    }
    void draw_scene(std::shared_ptr<Scene> scene)
    {
        for (auto iter = scene->begin(); iter != scene->end(); iter++)
        {
            if ((*iter).second->is_visible() == true)
                (*iter).second->accept(v);
        }
    }
    void set_camera(std::shared_ptr<Camera> camera)
    {
        v->set_camera(camera);
    }
    void clear_scene()
    {
        
    }
    ~DrawManager() = default;

    
private:
    std::shared_ptr<DrawVisitor> v;
};

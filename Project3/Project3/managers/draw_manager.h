#pragma once
#include <memory>
#include "base_managers.h"
#include "../objects/scene/scene.h"
#include "../objects/composite/composite.h"
#include "../objects/model/carcas_model.h"
#include "../drawing_classes/base_drawer.h"
#include "../drawing_classes/drawer_solution.h"
#include "../drawing_classes/abstract_factory.h"

//class Scene;

class DrawManager : BaseDrawManager
{
public:
    DrawManager(std::shared_ptr<DrawVisitor> v)
    {
        this->v = v;
        //sol = std::make_shared<DrawerSolution <AbstractFactory>>(v);
    }
    /*void draw(std::shared_ptr<BaseObject> obj)
    {
        sol->accept(obj);
    }*/
    void draw_scene(std::shared_ptr<Scene> scene)
    {
        std::shared_ptr<Composite> models = scene->get_models();
        for (auto iter = models->begin(); iter < models->end(); iter++)
        {
            (*iter)->accept(v);
        }
    }
    void clear_scene()
    {
        
    }
    ~DrawManager() = default;

    
private:
    std::shared_ptr<DrawVisitor> v;
    //std::shared_ptr<DrawerSolution <AbstractFactory>>sol;
};

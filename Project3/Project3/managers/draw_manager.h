#pragma once
#include <memory>
#include "base_managers.h"
#include "../objects/model/carcas_model.h"
#include "../drawing_classes/base_drawer.h"
#include "model_adapter.h"

class DrawManager : BaseDrawManager
{
public:
    DrawManager()
    {
        //_visitor = std::make_shared<ModelVisitor>(ModelVisitor());
        adapter = std::make_shared<DrawCarcasModelAdapter>(DrawCarcasModelAdapter());
    }
    ~DrawManager() = default;

    //void set_visitor(std::shared_ptr<ModelVisitor> visitor) {_visitor = visitor;}
    void set_adapter(std::shared_ptr<DrawCarcasModelAdapter> adapter) { adapter = adapter; }
    //void set_camera(std::shared_ptr<BaseCamera> camera) {_visitor->set_camera(camera);}
    //void set_drawer(std::shared_ptr<BaseDrawer> drawer) {_visitor->set_drawer(drawer);}
    void set_camera(std::shared_ptr<BaseCamera> camera) { adapter->set_camera(camera); }
    void set_drawer(std::shared_ptr<BaseDrawer> drawer) { adapter->set_drawer(drawer); }
    void draw_scene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<BaseCamera> cam)
    {
        set_drawer(drawer);
        set_camera(cam);
        for (const auto& kv : scene->_visible_objects)
        {
            auto obj_ptr = std::dynamic_pointer_cast<CarcassModel>(kv.second);
            adapter->set_adaptee(obj_ptr);
            adapter->request();
        }
    }
    void clear_scene(std::shared_ptr<BaseDrawer> drawer)
    {
        drawer->clear_scene();
    }
private:
    //std::shared_ptr<ModelVisitor> _visitor;
    std::shared_ptr<DrawCarcasModelAdapter> adapter;
};

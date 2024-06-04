#pragma once
#include "model_adapter.h"
#include "../objects/camera/camera.h"
#include "../drawing_classes/base_drawer.h"


class DrawCarcasModelAdapter : public ModelAdapter
{
public:
    void set_camera(std::shared_ptr<Camera> camera) { camera = camera; }
    void set_drawer(std::shared_ptr<BaseDrawer> drawer) { drawer = drawer; }

    virtual void request() override
    {
        if (adaptee && camera && drawer)
        {
            auto edges = adaptee->data->get_edges();
            for (auto edge : edges)
            {
                drawer->draw_line(get_projection(points.at(edge.get_p1())),
                    get_projection(points.at(edge.get_p2())));
            }
        }
    }
    My_Point get_projection(const My_Point& point)
    {
        return camera->get_projection(point);
    }
private:
    std::shared_ptr<Camera> camera;
    std::shared_ptr<BaseDrawer> drawer;
};
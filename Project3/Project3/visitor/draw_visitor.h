#pragma once
#include <memory>
#include "../drawing_classes/abstract_factory.h"
#include "../objects/model/point.h"
#include "abstract_visitor.h"

#include "../objects/model/carcas_model.h"
#include "../objects/camera/camera.h"

class DrawVisitor : public AbstractVisitor
{
public:
    DrawVisitor();
    DrawVisitor(const DrawVisitor& visitor) = default;
    ~DrawVisitor() = default;
    
    void set_camera(std::shared_ptr<Camera> camera) { this->camera = camera; }

protected:
    std::shared_ptr<AbstractFactory> factory;
    std::shared_ptr<Camera> camera;

    My_Point get_proection(const My_Point& point);
};


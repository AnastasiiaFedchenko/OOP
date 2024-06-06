#pragma once
#include "abstract_visitor.h"
#include "draw_visitor.h"

#include "../objects/model/carcas_model.h"
#include "../objects/camera/camera.h"

class DrawAll : public DrawVisitor
{
public:
    DrawAll();
    DrawAll(std::shared_ptr<AbstractFactory> factory, std::shared_ptr<Camera>  camera);
    DrawAll(const DrawAll& visitor);
    ~DrawAll() = default;

    void visit(BaseObject& obj) override;
    void visit(CarcassModel& carcass) override;
    void visit(Camera& camera) override;
    //void visit(CompositeObject& composite) override;
};


#pragma once
// #include "../objects/model/base_model.h"
// #include "../objects/camera/camera.h"
// #include "../objects/model/carcas_model.h"

class BaseObject;
class CarcassModel;
class Camera;

class AbstractVisitor
{
public:
    AbstractVisitor() {};
    virtual ~AbstractVisitor() = default;

    virtual void visit(BaseObject& obj) = 0;
    virtual void visit(CarcassModel& obj) = 0;
    virtual void visit(Camera& obj) = 0;
};


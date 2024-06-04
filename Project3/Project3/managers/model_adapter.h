#pragma once
#include "../objects/model/carcas_model.h"
class ModelAdapter
{
public:
    ModelAdapter() = default;
    virtual ~ModelAdapter() = default;
    virtual void set_adaptee(std::shared_ptr<CarcassModel> adaptee) { adaptee = adaptee; }
    virtual void request() = 0;

protected:
    std::shared_ptr<CarcassModel> adaptee;
};

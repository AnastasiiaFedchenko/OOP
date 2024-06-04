#pragma once
#include <memory>
#include <utility>

#include "point.h"
#include "carcas_model_data.h"
#include "base_model.h"
#include "../base_object.h"
#include "../../managers/model_visitor.h"
#include "../../managers/model_adapter.h"

class CarcassModel : public BaseModel
{
    friend class DrawCarcassModelAdapter;
    friend class ModelAdapter;
public:
    CarcassModel() : data(new CarcassModelData) { }
    explicit CarcassModel(const std::shared_ptr<CarcassModelData>& modelStructure) : data(modelStructure) { }
    explicit CarcassModel(const CarcassModel& model);
    CarcassModel(const std::shared_ptr<CarcassModel>& model);

    ~CarcassModel() override = default;

    virtual My_Point get_center() const override;
    void add_point(My_Point p);
    void add_edge(Edge e);
    virtual void transform(const TransformMatrix& mtr, const My_Point& center) override;

protected:
    std::shared_ptr<CarcassModelData> data;
};

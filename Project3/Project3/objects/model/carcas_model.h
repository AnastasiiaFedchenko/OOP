#pragma once
#include <memory>
#include <utility>

#include "point.h"
#include "carcas_model_data.h"
#include "base_model.h"
#include "../base_object.h"

class CarcassModel : public BaseModel
{
    friend class DrawCarcassModelAdapter;

public:
    CarcassModel() : data(new CarcassModelData) { }
    explicit CarcassModel(const std::shared_ptr<CarcassModelData>& modelStructure) : data(modelStructure) { }
    CarcassModel(const CarcassModel& model);

    ~CarcassModel() override = default;

    virtual Point get_center() const override;
    virtual void transform(const TransformMatrix& mtr, const Point& center) override;

protected:
    std::shared_ptr<CarcassModelData> data;
};

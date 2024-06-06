#pragma once
#include <memory>
#include <utility>

#include "point.h"
#include "carcas_model_data.h"
#include "base_model.h"
#include "../base_object.h"
// #include "../../visitor/draw_all.h"
#include "../../visitor/abstract_visitor.h"

class CarcassModel : public BaseModel
{
    // friend class DrawAll;
public:
    CarcassModel() : data(new CarcassModelData) { }
    explicit CarcassModel(const std::shared_ptr<CarcassModelData>& modelStructure) : data(modelStructure) { }
    explicit CarcassModel(const CarcassModel& model);
    CarcassModel(const std::shared_ptr<CarcassModel>& model);

    ~CarcassModel() override = default;

    virtual void accept(std::shared_ptr<AbstractVisitor> visitor)
	{
		visitor->visit(*this);
	}
    virtual My_Point get_center() const override;
    void add_point(My_Point p);
    void add_edge(Edge e);
    virtual void transform(const TransformMatrix& mtr, const My_Point& center) override;
    bool is_visible() override { return true; }

public:
    std::shared_ptr<CarcassModelData> data;
};

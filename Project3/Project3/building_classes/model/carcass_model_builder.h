#pragma once
#include "base_model_builder.h"
#include "../../objects/model/point.h"
#include "../../objects/model/edge.h"

class CarcassModelBuilder : public BaseModelBuilder
{
public:
    CarcassModelBuilder() = default;
    ~CarcassModelBuilder() = default;

    void build() override;
    void build_point(const Point& point) override;
    void build_edge(const Edge& edge) override;
    bool build_points();
    bool build_edges();

    bool is_build() const override;

    std::shared_ptr<CarcassModel> get() override;
private:
    std::vector<Point> points;
    std::vector<Edge> edges;
};


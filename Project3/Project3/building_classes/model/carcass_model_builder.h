#pragma once
#include "base_model_builder.h"
#include "../../objects/model/point.h"
#include "../../objects/model/edge.h"

class CarcassModelBuilder : public BaseModelBuilder
{
public:
    CarcassModelBuilder(std::shared_ptr<FileReader> reader);
    ~CarcassModelBuilder() = default;

    void build() override;
    bool build_point(const My_Point& point) override;
    bool build_edge(const Edge& edge) override;
    bool build_points();
    bool build_edges();

    bool is_build() const override;

    std::shared_ptr<CarcassModel> get() override;
private:
    std::vector<My_Point> points;
    std::vector<Edge> edges;
    std::shared_ptr<FileReader> reader;
};


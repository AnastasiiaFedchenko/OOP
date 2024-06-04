#pragma once
#include "../../objects/model/point.h"
#include "../../objects/model/edge.h"
#include "../../objects/model/carcas_model.h"
#include "../../objects/model/carcas_model_data.h"
#include "../base_builder.h"
#include "../reader/file_reader.h"
#include <memory>

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;

    virtual void build() override = 0;
    virtual bool build_point(const My_Point& point) = 0;
    virtual bool build_edge(const Edge& edge) = 0;
    virtual bool is_build() const override = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

protected:
    std::shared_ptr<CarcassModel> model;
    std::shared_ptr<FileReader> reader;
};
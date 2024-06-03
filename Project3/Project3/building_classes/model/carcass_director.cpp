#include "carcass_director.h"


CarcassDirector::CarcassDirector() {}

CarcassDirector::CarcassDirector(std::shared_ptr<CarcassModelBuilder> builder)
{
    this->builder = builder;
}

std::shared_ptr<BaseObject> CarcassDirector::create()
{
    builder->build_points();
    builder->build_edges();
    builder->build();
    return builder->get();
}

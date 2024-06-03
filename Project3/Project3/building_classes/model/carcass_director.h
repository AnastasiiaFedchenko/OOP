#pragma once

#include "../base_director.h"
#include "../../objects/base_object.h"
#include "carcass_model_builder.h"

class CarcassDirector : public BaseDirector
{
public:
    CarcassDirector();
    CarcassDirector(std::shared_ptr<CarcassModelBuilder> builder);

    std::shared_ptr<BaseObject> create() override;
private:
    std::shared_ptr<CarcassModelBuilder> builder;
};

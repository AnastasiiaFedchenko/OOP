#pragma once

#include <string>
#include <fstream>
#include <memory>

#include "../objects/base_object.h"

class BaseDirector
{
public:
    BaseDirector(){}
    virtual ~BaseDirector() = default;

    virtual std::shared_ptr<BaseObject> create() = 0;
};

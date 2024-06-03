#pragma once
#include "../objects/model/base_model.h"
#include "reader/base_reader.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual void build() = 0;
    virtual bool is_build() const = 0;
};
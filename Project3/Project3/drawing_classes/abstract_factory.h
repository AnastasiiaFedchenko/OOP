#pragma once
#include "base_drawer.h"
#include <memory>

class AbstractFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> create_drawer() = 0;
};
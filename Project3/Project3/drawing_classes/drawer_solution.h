#pragma once
#include <memory>
#include "base_drawer.h"
#include "abstract_factory.h"
#include "../base_solution.h"
#include "../objects/canvas.h"

template <typename Tfactory>
class DrawerSolution: BaseSolution
{
public:
    std::shared_ptr<BaseDrawer> create_drawer(canvas_t* canv)
    {
        std::shared_ptr<AbstractFactory> factory(new Tfactory(canv));
        return factory->create_drawer();
    }
};
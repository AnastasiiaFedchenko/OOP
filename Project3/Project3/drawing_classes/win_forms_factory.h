#pragma once
#include <memory>
#include "../objects/canvas.h"
#include "win_forms_drawer.h"
#include "abstract_factory.h"

class WinFormsFactory : public AbstractFactory
{
public:
    explicit WinFormsFactory(canvas_t* canv) : canvas(canv) {}
    std::shared_ptr<BaseDrawer> create_drawer() override
    {
        return std::make_shared<WinFormsDrawer>(canvas);
    }
private:
    canvas_t* canvas;
};
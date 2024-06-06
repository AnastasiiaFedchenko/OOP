#pragma once
#include <memory>
#include "base_drawer.h"
#include "abstract_factory.h"
#include "../base_solution.h"
#include "../objects/canvas.h"
#include "../visitor/draw_visitor.h"

template <typename Tfactory>
class DrawerSolution: BaseSolution
{
public:
    DrawerSolution() {}
    explicit DrawerSolution(std::shared_ptr<DrawVisitor> visitor) : visitor(visitor) {}

    ~DrawerSolution() = default;

    void set_visitor(std::shared_ptr<DrawVisitor> visitor) { this->visitor = visitor; }
    void accept(std::shared_ptr<BaseModel> obj) { obj->accept(this->visitor); }
    void set_camera(std::shared_ptr<Camera> camera) { this->visitor->set_camera(camera); }

protected:
    std::shared_ptr<DrawVisitor> visitor;
};
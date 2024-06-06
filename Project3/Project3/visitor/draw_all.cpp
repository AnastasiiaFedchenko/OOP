#include "draw_all.h"


DrawAll::DrawAll() {}

DrawAll::DrawAll(std::shared_ptr<AbstractFactory> factory, std::shared_ptr<Camera>  camera)
{
    this->factory = factory;
    this->camera = camera;
}

DrawAll::DrawAll(const DrawAll& visitor)
{
    this->camera = visitor.camera;
    this->factory = visitor.factory;
}

void DrawAll::visit(CarcassModel& carcass)
{
    // carcas.accept(std::make_shared<DrawAll>(*this));

    auto points = carcass.data->get_points();
    auto edges = carcass.data->get_edges();

    auto drawer = this->factory->create_drawer();

    for (auto& edge : edges)
    {
        drawer->draw_line(get_proection(points[edge.get_p1()]),
                          get_proection(points[edge.get_p2()]));
    }

    return;
}

void DrawAll::visit(BaseObject& object)
{
    return;
}

void DrawAll::visit(Camera& camera)
{
    return;
}

/*void DrawAll::visit(CompositeObject& obj)
{
    obj.accept(std::make_shared<DrawAll>(*this));
}*/

#include "draw_visitor.h"

DrawVisitor::DrawVisitor() {}


My_Point DrawVisitor::get_proection(const My_Point& point)
{
    return camera->get_projection(point);
}

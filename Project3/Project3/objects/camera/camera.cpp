#include "camera.h"

void Camera::transform(Transform& mtr, const My_Point& center)
{
    My_Point diff = My_Point(0, 0, 0) - center;
    this->data->set_location(this->data->get_location() + diff);
    mtr.imply(this->data->get_location());

    this->data->set_location(this->data->get_location() - diff);
}

My_Point Camera::get_projection(const My_Point& point)
{
    My_Point p(point);
    p.set_z(0);
    p.set_x(p.get_x() - data->get_location().get_x());
    p.set_y(p.get_y() - data->get_location().get_y());
    return p;
}

My_Point Camera::get_center() const
{
    return this->data->get_location();
}
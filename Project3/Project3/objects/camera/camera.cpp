#include "camera.h"

void Camera::transform(const TransformMatrix& mtr, const My_Point& center)
{
    My_Point diff = My_Point(0, 0, 0) - center;
    this->data->set_location(this->data->get_location() + diff);

    TransformMatrix cur_place(1, 4);
    cur_place = {{this->data->get_location().get_x(), this->data->get_location().get_y(), 
                this->data->get_location().get_z(), 1}};
    TransformMatrix new_place = cur_place * mtr;

    this->data->set_location(My_Point(new_place.get(0,0), new_place.get(0, 1), new_place.get(0, 02)));

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
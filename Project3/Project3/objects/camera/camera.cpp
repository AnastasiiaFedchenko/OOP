#include "camera.h"

void Camera::transform(const TransformMatrix& mtr, const Point& center)
{
    Point diff = Point(0, 0, 0) - center;
    this->data->set_location(this->data->get_location() + diff);

    TransformMatrix cur_place(1, 4);
    cur_place = {{this->data->get_location().get_x(), this->data->get_location().get_y(), 
                this->data->get_location().get_z(), 1}};
    TransformMatrix new_place = cur_place * mtr;

    this->data->set_location(Point(new_place.get(0,0), new_place.get(0, 1), new_place.get(0, 02)));

    this->data->set_location(this->data->get_location() - diff);
}

Point Camera::get_center() const
{
    return this->data->get_location();
}
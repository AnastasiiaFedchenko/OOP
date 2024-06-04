#include "camera_data.h"

My_Point& CameraData::get_location() { return this->location; }
My_Point& CameraData::get_direction() { return this->direction; }

void CameraData::set_location(My_Point& new_location) { this->location = new_location; }
void CameraData::set_direction(My_Point& new_direction) { this->direction = new_direction; }
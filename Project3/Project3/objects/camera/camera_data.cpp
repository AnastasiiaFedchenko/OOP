#include "camera_data.h"

Point& CameraData::get_location() { return this->location; }
Point& CameraData::get_direction() { return this->direction; }

void CameraData::set_location(Point& new_location) { this->location = new_location; }
void CameraData::set_direction(Point& new_direction) { this->direction = new_direction; }
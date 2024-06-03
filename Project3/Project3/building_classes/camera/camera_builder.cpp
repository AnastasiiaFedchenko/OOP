#include "camera_builder.h"

void CameraBuilder::build() { camera = std::make_shared<Camera>(); }

void CameraBuilder::build_location(const Point& location, const Point& direction) 
{
    camera = std::make_shared<Camera>(std::make_shared<CameraData>(location, direction));
}

bool CameraBuilder::is_build() const { return nullptr != camera; }

std::shared_ptr<Camera> CameraBuilder::get() { return camera; }
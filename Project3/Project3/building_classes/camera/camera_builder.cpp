#include "camera_builder.h"

CameraBuilder::CameraBuilder(std::shared_ptr<FileReader> reader)
{
    this->reader = reader;
}

void CameraBuilder::build() 
{
    camera = std::make_shared<Camera>(std::make_shared<CameraData>(location, direction));
}

bool CameraBuilder::build_location() 
{
    if (!this->reader->is_open())
        this->reader->open();
    this->location = this->reader->read_point();
    return true;
    
}

bool CameraBuilder::build_direction()
{
    if (!this->reader->is_open())
        this->reader->open();
    this->direction = this->reader->read_point();
    return true;

}

bool CameraBuilder::is_build() const { return nullptr != camera; }

std::shared_ptr<Camera> CameraBuilder::get() 
{
    return camera; 
}
#include "carcass_model_builder.h"

CarcassModelBuilder::CarcassModelBuilder(std::shared_ptr<FileReader> reader)
{
    this->reader = reader;
}

void CarcassModelBuilder::build() 
{ 
    model = std::make_shared<CarcassModel>(std::make_shared<CarcassModelData>(points, edges));
}


bool CarcassModelBuilder::build_point(const My_Point& point)
{
    if (!is_build())
        return false;

    model->add_point(point);
    return true;
}


bool CarcassModelBuilder::build_edge(const Edge& edge)
{
    if (!is_build())
        return false;

    model->add_edge(edge);
    return true;
}

bool CarcassModelBuilder::build_points()
{
    if (!this->reader->is_open())
        this->reader->open();
    this->points = this->reader->read_points();
    return true;
}
bool CarcassModelBuilder::build_edges()
{
    if (this->points.size() == 0)
        //throw std::exception();
    if (!this->reader->is_open())
        this->reader->open();
    this->edges = this->reader->read_edges(this->points.size());
    return true;
}

bool CarcassModelBuilder::is_build() const { return (points.size() != 0 && edges.size() != 0); }

std::shared_ptr<CarcassModel> CarcassModelBuilder::get() 
{ 
    return model; 
}
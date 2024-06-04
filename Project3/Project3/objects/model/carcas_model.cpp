#include "carcas_model.h"

CarcassModel::CarcassModel(const CarcassModel& model)
{
   this->data = model.data;
   this->id = model.id;
}

CarcassModel::CarcassModel(const std::shared_ptr<CarcassModel>& model)
{
   this->data = model->data;
   this->id = model->id;
}

My_Point CarcassModel::get_center() const { return data->get_center(); }
void CarcassModel::add_point(My_Point p)
{
    this->data->add_point(p);
}
void CarcassModel::add_edge(Edge e)
{
    this->data->add_edge(e);
}
void CarcassModel::transform(const TransformMatrix& mtr, const My_Point& center_p)
{
    data->transform(mtr, center_p);
}
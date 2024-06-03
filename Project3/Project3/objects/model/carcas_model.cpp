#include "carcas_model.h"

CarcassModel::CarcassModel(const CarcassModel& model)
{
   this->data = model.data;
   this->id = model.id;
}

Point CarcassModel::get_center() const { return data->get_center(); }

void CarcassModel::transform(const TransformMatrix& mtr, const Point& center_p)
{
    data->transform(mtr, center_p);
}
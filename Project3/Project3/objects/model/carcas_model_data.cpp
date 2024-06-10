#include "carcas_model_data.h"

CarcassModelData::CarcassModelData(std::vector<My_Point>& points, std::vector<Edge>& edges) :
    center_p{ }, points(points), edges(edges) { }


CarcassModelData::CarcassModelData(std::vector<My_Point>& points, std::vector<Edge>& edges, My_Point& center_p) :
    center_p(center_p), points(points), edges(edges) { }

const std::vector<My_Point>& CarcassModelData::get_points() const { return this->points; }

const std::vector<Edge>& CarcassModelData::get_edges() const { return this->edges; }

const My_Point CarcassModelData::get_center() const { return this->center_p; }

void CarcassModelData::add_point(const My_Point& point)
{
    this->points.push_back(point);
    this->update_center();
}

void CarcassModelData::add_edge(const Edge& edge) { edges.push_back(edge); }

void CarcassModelData::update_center()
{
    this->center_p = My_Point(0, 0, 0);

    for (int i = 0; i < points.size(); i++)
        center_p = center_p + points[i].get();

    center_p = My_Point(center_p.get_x() / points.size(), center_p.get_y() / points.size(),  center_p.get_z() / points.size());
}

void CarcassModelData::move_points_to_origin(const My_Point& center)
{
    My_Point diff = My_Point(0, 0, 0) - center;

    TransformShift mtr(diff.get_x(), diff.get_y(), diff.get_z());

    this->transform_points(mtr);
    this->update_center();
}

void CarcassModelData::move_points_to_center(const My_Point& center)
{
    My_Point diff = center - My_Point(0, 0, 0);

    TransformShift mtr(diff.get_x(), diff.get_y(), diff.get_z());

    this->transform_points(mtr);
    this->update_center();
}

void CarcassModelData::transform_points(Transform& mtr)
{
    for (auto& p : points)
        mtr.imply(p);
}

void CarcassModelData::transform(Transform& mtr, const My_Point& center)
{
    update_center();
    move_points_to_origin(center);
    transform_points(mtr);
    move_points_to_center(center);
}
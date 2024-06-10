#pragma once
#include <vector>
#include "../../matrix/transform_matrix.h"
#include "point.h"
#include "edge.h"

class CarcassModelData
{
public:
    CarcassModelData() = default;
    CarcassModelData(std::vector<My_Point>& points, std::vector<Edge>& edges);
    CarcassModelData(std::vector<My_Point>& points, std::vector<Edge>& edges, My_Point& center_p);

    ~CarcassModelData() = default;

    const std::vector<My_Point>& get_points() const;
    const std::vector<Edge>& get_edges() const;
    const My_Point get_center() const;

    void add_point(const My_Point& point);
    void add_edge(const Edge& edge);
    void update_center();

    void move_points_to_origin(const My_Point& center);
    void move_points_to_center(const My_Point& center);
    void transform_points(Transform& mtr);
    void transform(Transform& mtr, const My_Point& center);

private:
    My_Point center_p;

    std::vector<My_Point> points;
    std::vector<Edge> edges;
};
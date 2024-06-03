#pragma once
#include <vector>
#include "../../matrix/transform_matrix.h"
#include "point.h"
#include "edge.h"

class CarcassModelData
{
public:
    CarcassModelData() = default;
    CarcassModelData(std::vector<Point>& points, std::vector<Edge>& edges);
    CarcassModelData(std::vector<Point>& points, std::vector<Edge>& edges, Point& center_p);

    ~CarcassModelData() = default;

    const std::vector<Point>& get_points() const;
    const std::vector<Edge>& get_edges() const;
    const Point get_center() const;

    void add_point(const Point& point);
    void add_edge(const Edge& edge);
    void update_center();

    void move_points_to_origin(const Point& center);
    void move_points_to_center(const Point& center);
    void transform_points(const TransformMatrix& mtr);
    void transform(const TransformMatrix& mtr, const Point& center);

private:
    Point center_p;

    std::vector<Point> points;
    std::vector<Edge> edges;
};
#include "carcass_model_builder.h"

void CarcassModelBuilder::build() { model = std::make_shared<CarcassModelData>(); }


void CarcassModelBuilder::build_point(const Point& point)
{
    if (!is_build())
        return;

    model->add_point(point);
}


void CarcassModelBuilder::build_edge(const Edge& edge)
{
    if (!is_build())
        return;

    model->add_edge(edge);
}

bool CarcassModelBuilder::build_points()
{
    int number_of_points = int(reader->read());
    bool correct = true;

    for (int i = 0; correct && i < number_of_points; i++)
    {
        double x, y, z;
        x = this->reader->read();
        y = this->reader->read();
        z = this->reader->read();

        this->points.push_back(Point(x, y, z));
    }

    return correct;
}
bool CarcassModelBuilder::build_edges()
{
    bool correct = true;
    int number_of_links = int(this->reader->read());
    for (int i = 0; correct && i < number_of_links; i++)
    {
        std::size_t A, B;
        A = this->reader->read();
        B = this->reader->read();

        this->edges.push_back(Edge(A, B));
    }

    return correct;

}

bool CarcassModelBuilder::is_build() const { return nullptr != model; }

std::shared_ptr<CarcassModel> CarcassModelBuilder::get() { return std::make_shared<CarcassModel>(CarcassModel(model)); }
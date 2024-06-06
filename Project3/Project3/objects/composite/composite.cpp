#include "composite.h"

Composite::Composite(std::shared_ptr<BaseObject>& element)
{
    elements.push_back(element);
    update_center();
}


Composite::Composite(const std::vector<std::shared_ptr<BaseObject>>& vector)
{
    elements = vector;
    update_center();
}


bool Composite::add(const std::shared_ptr<BaseObject>& element)
{
    elements.push_back(element);
    update_center();

    return true;
}


bool Composite::remove(const std::size_t& id)
{
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i]->get_id() == id)
        {
            elements.erase(std::next(elements.begin(), i));
            update_center();
            return true;
        }
    }
    return false;
}

void Composite::update_center()
{
    center_p = My_Point(0, 0, 0);

    for (const auto& element : elements)
        center_p = center_p + element->get_center();

    center_p = My_Point(center_p.get_x() / elements.size(),
                     center_p.get_y() / elements.size(),
                     center_p.get_z() / elements.size());
}

bool Composite::is_visible() { return false; }

bool Composite::is_composite() { return true; }

std::shared_ptr<BaseObject> Composite::get(const std::size_t& id) 
{ 
    for (int i = 0; i < elements.size(); i++)
        if (elements[i]->get_id() == id)
            return elements[i];
    return nullptr;
}

My_Point Composite::get_center() const { return center_p; }

void Composite::move_elems_to_origin(const My_Point& center)
{
    My_Point diff = My_Point(0, 0, 0) - center;

    TransformMatrix mtr(4, 4);
    mtr = { { 1, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 1, 0 },
            { diff.get_x(), diff.get_y(), diff.get_z(), 1 } };

    this->transform_elems(mtr);
    this->update_center();
}

void Composite::move_elems_to_center(const My_Point& center)
{
    My_Point diff = center - center_p;

    TransformMatrix mtr(4, 4);
    mtr = { { 1, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 1, 0 },
            { diff.get_x(), diff.get_y(), diff.get_z(), 1 } };

    this->transform_elems(mtr);
    this->update_center();
}

void Composite::transform_elems(const TransformMatrix& mtr)
{
    for (const auto& element : elements)
    {
        element->update_center();
        element->transform(mtr, center_p);
    }
}

void Composite::transform(const TransformMatrix& mtr, const My_Point& center)
{
    update_center();

    move_elems_to_origin(center);
    transform_elems(mtr);
    move_elems_to_center(center);
}

Iterator Composite::begin() { return elements.begin(); }


Iterator Composite::end() { return elements.end(); }